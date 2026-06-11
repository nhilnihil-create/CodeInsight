#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int  long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
/// age ye mosh dp ro baze dashti dp tedad baz shodeye baste nashode yadet nare !!
/// joooob zadam
const int N=202+100;
char c[N][N],a[N][N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> c[i][j];
        }
    }
    ll ans=0;
    for (int k=0;k<n;k++){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                ll x=(i+k)%n;
                ll y=j;
                a[i][j]=c[x][y];
            }
        }
        ll p1=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (a[i][j]!=a[j][i]){
                    p1=1;
                }
            }
        }
        if (!p1){
            //cout << k << endl;
            ans+=n;
        }
    }
    cout << ans;
}
