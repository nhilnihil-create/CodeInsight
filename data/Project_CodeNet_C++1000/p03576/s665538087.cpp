#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, l;
    cin >> n >> l;

    pair<ll, ll> p[n];
    rep(i, 0, n){
        cin >> p[i].first >> p[i].second;
    }

    ll ans = 9000000000000000000;
    rep(i, 0, n){
        rep(j, i + 1, n){
            rep(k, 0, n){
                rep(m, k + 1, n){
                    ll count = 0;
                    rep(o, 0, n){
                        if(min(p[i].first, p[j].first) <= p[o].first &&
                                max(p[i].first, p[j].first) >= p[o].first &&
                                min(p[k].second, p[m].second) <= p[o].second &&
                                max(p[k].second, p[m].second) >= p[o].second){
                            count++;
                        }
                    }
                    if(count >= l){
                        ans = min(ans, ll(abs(p[i].first - p[j].first)) * ll(abs(p[k].second - p[m].second)));
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
