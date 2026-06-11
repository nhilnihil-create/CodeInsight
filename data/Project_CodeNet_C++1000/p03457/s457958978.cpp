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
    vector<ll> t(n), x(n), y(n);
    rep(i, n) cin >> t[i] >> x[i] >> y[i];

    ll ct = 0, cx = 0, cy = 0;

    rep(i, n) {
        ll dt = t[i] - ct;
        ll dx = abs(x[i] - cx);
        ll dy = abs(y[i] - cy);

        if (dx + dy <= dt && (dt - dx - dy) % 2 == 0) {
            //ok            
        } 
        else {
            put("No");
            return 0;
        }
        cx = x[i];
        cy = y[i];
        ct = t[i];
    }

    put("Yes");

    

    return 0;
}