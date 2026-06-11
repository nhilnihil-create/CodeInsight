#include <bits/stdc++.h>
#define ll long long
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define divceil(A, B) ((A + (B - 1)) / B)
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr

using namespace std;

int main(){

    int n,k;
    cin >> n >> k;

    vector<pair<ll,ll>> v;

    rep(i,n){
        int x,y;
        cin >> x >> y;

        v.pback(mpair(x,y));

    }
    
    ll ans = LLONG_MAX;

    for(int a = 0; a <= n - 2; a++){
        for(int b = 0; b <= n - 1; b++){
            for(int c = 0; c <= n - 2; c++){
                for(int d = 0; d <= n - 1; d++){

                    ll left = min(v[a].first, v[b].first);
                    ll right = max(v[a].first, v[b].first);
                    ll bottom = min(v[c].second, v[d].second);
                    ll top = max(v[c].second, v[d].second);

                    int count = 0;

                    rep(i,n){
                        ll x = v[i].first;
                        ll y = v[i].second;
                        if(left <= x && x <= right && bottom <= y && y <= top){
                            count++;
                        }
                    }

                    if(count >= k){
                        ans = min(ans, (right - left) * (top - bottom));
                    }
                }
            }
        }
    }





    cout << ans << endl;
    return 0;

}
