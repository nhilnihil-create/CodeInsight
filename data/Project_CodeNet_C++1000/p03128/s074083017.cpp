#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

ll dp[10000];
ll conv(ll i){
    if(i == 1) return 2;
    if(i == 2) return 5;
    if(i == 3) return 5;
    if(i == 4) return 4;
    if(i == 5) return 5;
    if(i == 6) return 6;
    if(i == 7) return 3;
    if(i == 8) return 7;
    if(i == 9) return 6;
}

int main(void){
    ll n, m;
    cin >> n >> m;

    ll a[m];
    rep(i, 0, m){
        cin >> a[i];
    }
    sort(a, a + m, greater<ll>());

    rep(i, 0, n + 1){
        rep(j, 0, m){
            if(i - conv(a[j]) < 0){
                continue;
            }else{
                if(i - conv(a[j]) == 0 || dp[i - conv(a[j])] != 0){
                    dp[i] = max(dp[i - conv(a[j])] + 1, dp[i]);
                }
            }
        }
    }

    ll tmp = n;
    rrep(i, dp[n], 1){
        rep(j, 0, m){
            if(tmp - conv(a[j]) >= 0){
                if(i == 1){
                    if(tmp - conv(a[j]) == 0){
                        cout << a[j];
                        break;
                    }
                }else if(dp[tmp - conv(a[j])] == i - 1){
                    tmp -= conv(a[j]);
                    cout << a[j];
                    continue;
                }
            }
        }
    }
    cout << endl;
    return 0;
}
