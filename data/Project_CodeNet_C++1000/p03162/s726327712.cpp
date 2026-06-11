#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fs first
#define sn second
#define mp make_pair
typedef long long int ll;

template<typename T, typename U> static inline void amin(T &x, U y){if (y < x)x = y;}  
template<typename T, typename U> static inline void amax(T &x, U y){if (x < y)x = y;} 

const ll mod = 1e9+7; 

//void precomp(){}

void solve(){
    
    int n;cin>>n;ll a[n][3];
    for(auto& i: a){
    	for(auto& j: i)cin>>j;
    }
    ll dp[n][3]={0};
    dp[0][0]=a[0][0];dp[0][1]=a[0][1];dp[0][2]=a[0][2];
    for(int i=1;i<n;i++){
        dp[i][0]=a[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=a[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=a[i][2]+max(dp[i-1][1],dp[i-1][0]);
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<"\n";
}

int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);

    //precomp();
	
	//int tc;cin>>tc;while(tc--)
    solve();

    return 0;
}