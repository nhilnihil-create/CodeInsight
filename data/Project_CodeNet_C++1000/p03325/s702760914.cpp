#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define rall(x) (x).rbegin(),(x).rend()
#define accum(x) accumulate((x).begin(),(x).end(),0)

int main(){
	int n; cin>>n;
	vector<int> v;
	rep(i,n){
		int a; cin>>a;
		if(a%2==0) v.push_back(a);
	}
	if(v.size()==0){cout<<0<<endl; return 0;}
	sort(rall(v));
	int cnt=0;
	while(!v.empty()){
		cnt++;
		int mx=v.size()-1;
		for(int i=0; i<mx-1; i++) v[i]*=3;
		if((v[mx]/2)%2==0) v[mx]/=2;
		else v.pop_back();
	}
	cout<<cnt<<endl;
}