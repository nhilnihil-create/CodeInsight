#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> mat(n);
    for(int &x:mat) cin>>x;
    
    vector<int> dp(k+1);
    
    for(int i=0;i<=k;i++){
        for(int x:mat){
            if(i-x>=0 && dp[i-x]==0){
                dp[i]=true;
            }
        }
    }
    if(dp[k]) cout<<"First";
    else cout<<"Second";
}

int main() {
	// your code goes here
	//freopen("inptmp0.txt","r",stdin);
	int T;
	
	//cin>>T;
	T=1;
	while(T--){
	    solve();
	}
	return 0;
}
