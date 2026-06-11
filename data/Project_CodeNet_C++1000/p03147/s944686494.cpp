#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define accum(x) accumulate((x).begin(),(x).end(),0)

int main(){
	int n; cin>>n;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	int sum=accum(v);
	int cnt=0;
	while(sum!=0){
		bool flg=false;
		int zero=0;
		for(int i=0; i<n; i++){
			if(v[i]!=0) {v[i]--; flg=true;}
			else if(flg&&v[i]==0) {zero++; flg=false;}
		}
		if(flg) cnt++;
		cnt+=zero;
		sum=accum(v);
	}
	cout<<cnt<<endl;
}