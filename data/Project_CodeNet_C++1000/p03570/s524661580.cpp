#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
//#define int  long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
/// age ye mosh dp ro baze dashti dp tedad baz shodeye baste nashode yadet nare !!
/// joooob zadam
const int N=2e5+100;
char c[N];
ll dp[(1<<26)];

int32_t main(){
    string s;
    cin >> s;
    ll n=s.size();
    for (int i=1;i<=n;i++){
        c[i]=s[i-1];
    }
    ll t=0;
    for (int i=0;i<(1<<26);i++)
        dp[i]=1e6;
    dp[0]=0;
    for (int i=0;i<26;i++){
   //     dp[(1<<i)]=0;
    }
    for (int i=1;i<=n;i++){
        //cout << i << endl;
        ll z=c[i]-'a';
        t ^= (1<<z);
        ll mi=dp[t];
        for (int j=0;j<26;j++){
            t ^= (1<<j);
            mi=min(dp[t],mi);
            t ^= (1<<j);
        }
        if (t==0){
            mi=-1;
        }
        dp[t]=mi+1;
        //cout << t << " " << dp[t]  << endl;
        if (i==n){
            cout << max((ll)1,dp[t]) << endl;
        }
    }


}
