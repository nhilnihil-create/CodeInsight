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
    string ABCD;
    cin >> ABCD;

    vector<int> v(4);
    rep(i, ABCD.size()) v[i] = ABCD[i] - '0';

    rep(pat, 1 << 3) {
        int x = v[0];
        rep(i, 3) {
            if ((pat >> i) & 1) {
                x += v[i + 1];
            }
            else {
                x -= v[i + 1];
            }
        }
        if (x == 7) {
            printf("%d%c%d%c%d%c%d=7\n",
                v[0],
                (pat >> 0) & 1 ? '+' : '-',
                v[1],
                (pat >> 1) & 1 ? '+' : '-',
                v[2],
                (pat >> 2) & 1 ? '+' : '-',
                v[3]
            );
            return 0;

        }
    }

    return 0;
}