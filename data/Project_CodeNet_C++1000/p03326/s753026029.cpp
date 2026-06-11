#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;


int main(){

    int n, m;
    cin >> n >> m;

    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> z(n);

    rep(i, n){
        ll a,b,c;
        cin >> a >> b >> c;

        x[i] = a;
        y[i] = b;
        z[i] = c;
    }

    ll ans = 0;

    for(int i = -1; i <= 1; i = i + 2){
        for(int j = -1; j <= 1; j = j + 2){
            for(int k = -1; k <= 1; k = k + 2){

                vector<pair<ll,int>> tmpv;
                rep(l, n){
                    ll tmp = i * x[l] + j * y[l] + k * z[l];

                    tmpv.pback(mpair(tmp, l));
                }

                sort(ALL(tmpv));
                reverse(ALL(tmpv));

                ll xsum = 0;
                ll ysum = 0;
                ll zsum = 0;

                rep(l, m){
                    int index = tmpv[l].second;

                    xsum += x[index];
                    ysum += y[index];
                    zsum += z[index];
                }

                ans = max(ans, abs(xsum) + abs(ysum) + abs(zsum));

            }
        }
    }

    cout << ans << endl;


    return 0;
}
