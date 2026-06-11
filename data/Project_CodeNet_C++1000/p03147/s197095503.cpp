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
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<vector<int>> M(101, vector<int>(101));

    rep(i, n) {
        rep (j, h[i]) {
            M[j][i] = 1;
        }
    }

    
    int cnt = 0;
    rep (j, 101) {
        int prev = 0;
        rep(i, n) {
            if (prev == 0 && M[j][i] == 1) {
                // put(i)
                // put(j)
                // put("===")
                cnt++;
            }
            prev = M[j][i];
        }
    }

    put(cnt);

    return 0;
}