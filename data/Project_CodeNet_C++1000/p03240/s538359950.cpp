#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n), h(n);
    rep(i, n) cin >> x[i] >> y[i] >> h[i];

    ll maxH = *max_element(all(h));
    ll maxX, maxY;
    rep(i, n) if (h[i] == maxH) {
        maxX = x[i];
        maxY = y[i];
        break;
    }

    rep(Cx, 101) rep(Cy, 101) {
        ll H = maxH + abs(maxX - Cx) + abs(maxY - Cy);
        // if (Cx == 2 && Cy == 2) {
        //     cout << "//" << H << endl;
        // }

        bool ok = true;
        rep(i, n) {
            if (max(0LL, H - abs(x[i] - Cx) - abs(y[i] - Cy)) != h[i]){
                ok = false;
                break;
            }
        }   

        if (ok) {
            cout << Cx << " " << Cy << " "<< H << endl;
        }
    }

    

    return 0;
}