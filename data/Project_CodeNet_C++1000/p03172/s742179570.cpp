#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define fo(i,CApiTaL_N) for(int i=0; i<CApiTaL_N; i++)
#define Fo(i,k,CApiTaL_N) for(int i=k; i<CApiTaL_N; i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it=a.begin(); it!=a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int t;
const int mxN=100, mxK=1e5, mod=1e9+7;
int n,k;
vl dp(mxK+1),a(mxN+1),cumsum(mxK+1);

void test_case(){
    cin>>n>>k;
    fo(i,n)cin>>a[i];
    dp[0]=1;
    cumsum[0]=1;
    for(auto e=1; e<k+1; e++){
        cumsum[e]=(cumsum[e-1]+dp[e]);
    }
    Fo(i,0,n){
        auto lim=a[i];
        for(int j=k; j>=0; j--){
            // Fo(p,1,lim+1){
            //     if(j-p<0)continue;
            //     dp[j]=(dp[j]+dp[j-p])%mod;
            // }
            ll total=0;
            if(!j)total=0;
            else{
                if(j-lim<=0){
                    total=cumsum[j-1];
                }else{
                    total=cumsum[j-1]-cumsum[j-lim-1];
                }
            }
            // cout<<j<<" "<<lim<<" "<<total<<" "<<i<<endl;
            dp[j]=(dp[j]+total)%mod;
        }
        for(auto e=1; e<k+1; e++){
            cumsum[e]=(cumsum[e-1]+dp[e]);
        }
    }
    cout<<dp[k]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }
    
    return 0;
}