#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <complex>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

const ll MOD = 1000000007;

int main(){
    int n; cin >> n;
    int c[n];
    rep(i,n){
        cin >> c[i];
        c[i]--;
    }
    if(n<=2){
        cout << 1 << endl;
        return 0;
    }
    vector<int> a(n);
    int k=1;
    a[0]=c[0];
    rep(i,n-1){
        if(c[i]!=c[i+1]){
            a[k]=c[i+1];
            k++;
        }
    }
    ll dp[n];
    vector<ll> plus(n,0);
    rep(i,k){
        if(i==0){
            dp[i]=1;
            plus[a[i]]=1;
            continue;
        }
        dp[i] = (dp[i-1]+plus[a[i]]) % MOD;
        dp[i] %= MOD;
        plus[a[i]]+=dp[i-1];
        plus[a[i]] %= MOD;
        //rep(i,n) cout << plus[i] << " "; cout << endl;
    }
    cout << dp[k-1] << endl;
    return 0;
}
