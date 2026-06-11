#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

void solve(){
	int lacnt=0,lbcnt=0,gbcnt=0;
	int n;
	cin>>n;
	int a,b;
	cin>>a>>b;
	vector<int>p(n);
	for(int i=0; i<n; i++)cin>>p[i];
	for(int i=0; i<n; i++){
		if(p[i]<=a){
			lacnt+=1;
		}
		else if(p[i]<=b){
			lbcnt+=1;
		}
		else{
			gbcnt+=1;
		}
	}
	cout<<min(lacnt, min(lbcnt, gbcnt))<<endl;
}

signed main(){
	//while(1)
	solve();
}