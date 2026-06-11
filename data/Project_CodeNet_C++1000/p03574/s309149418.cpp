#include <bits/stdc++.h>
#define ll long long int
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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<string> t(h);
    rep(i, h) t[i] = s[i];

    rep(i, h) rep(j, w) {
        if (s[i][j] == '.') {
            int cnt = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (i + dy >= 0 && i + dy <h && 0 <= j + dx && j + dx < w) {
                        cnt += s[i+dy][j+dx] == '#' ? 1 : 0;
                    }
                }
            }
            t[i][j] = '0' + cnt;
        }
    }

    rep(i, h) put(t[i])

    return 0;
}