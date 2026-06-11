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
    
    int n,k=2;cin>>n;ll h[n];for(auto& i: h)cin>>i;
    vector<ll> dp(n,LONG_MAX);
    dp[0]=0;
    for(int i=1;i<n;i++){
    	for(int j=1;j<=k;j++){if(j>i)break;amin(dp[i],dp[i-j]+abs(h[i]-h[i-j]));}
    }
    cout<<dp[n-1]<<"\n";
}

int main(){
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);

    //precomp();
	
	//int tc;cin>>tc;while(tc--)
    solve();

    return 0;
}