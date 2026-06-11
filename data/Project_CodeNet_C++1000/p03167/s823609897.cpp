#include<bits/stdc++.h>
#define mx 1000000007
#define ll long long int

using namespace std;

ll dp[1003][1003]={0},h,w;
char grid[1001][1001];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll h,w;
    cin>> h >> w ;
    for(ll i=1;i<=h;++i){
    	string str;
    	cin>> str;
        for(ll j=1;j<=w;++j){
            grid[i][j] = str[j-1] ;
        }
    }
    for(ll i=0;i<=h+1;++i){
        grid[i][w+1]='#';
    }
    for(ll i=0;i<=w+1;++i){
        grid[h+1][i]='#';
    }
    dp[h][w]=1;
    for(ll i=h;i>=1;--i){
        for(ll j=w;j>=1;--j){
        	if(grid[i][j]=='#'){
        		dp[i][j]=0;
        		continue;
        	}
            ll d=0,f=0;
            if(grid[i+1][j]=='.')
                d=dp[i+1][j];
            if(grid[i][j+1]=='.')
                f=dp[i][j+1];
            dp[i][j]=(dp[i][j]+d+f)%mx ;
        }
    }
    cout<< dp[1][1] ;
	return 0;
}
