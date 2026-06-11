#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
	int n; cin>>n;
	vector<int> v;
	rep(i,n){
		int a; cin>>a;
		if(a%2==0) v.push_back(a);
	}
	if(v.size()==0){cout<<0<<endl; return 0;}
	int ans=0;
	for(int i=0; i<v.size(); i++){
		int cnt=0;
		while(v[i]%2!=1){
			v[i]/=2;
			cnt++;
		}
		ans+=cnt;
	}
	cout<<ans<<endl;
}