#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define x first
#define y second

using pt = pair<int, int>;

int n, inside;
pt a[55];

void solve(){
    cin >> n >> inside;
    for(int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    
    ll ans = LLONG_MAX;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
             for(int k = 0; k < n; ++k){
                for(int l = k+1; l < n; ++l){
                    int mix = min(a[i].x, a[j].x), mxx = max(a[i].x, a[j].x);
                    int miy = min(a[k].y, a[l].y), mxy = max(a[k].y, a[l].y);
                    int cnt = 0;
                    for(int m = 0; m < n; ++m){  
                        if(a[m].x >= mix && a[m].x <= mxx && a[m].y >= miy && a[m].y <= mxy){
                            cnt++;
                        }
                    }

                    if(cnt >= inside){
                        ll area = (ll)(mxx-mix) * (mxy-miy);
                        ans = min(ans, area);
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}