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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<int> c(n), d(n);
    rep(i, n) cin >> c[i] >> d[i];

    
    typedef std::pair<int, int> pair;
    // 小さい順
    vector<pair> C;
    rep(i, n) C.push_back(pair(i, c[i]));
    sort(all(C), [](const pair& lhs, const pair& rhs) {
        return lhs.second < rhs.second;
    });

    // 大きい順
    vector<pair> B;
    rep(i, n) B.push_back(pair(i, b[i]));
    sort(all(B), [](const pair& lhs, const pair& rhs) {
        return lhs.second < rhs.second;
    });
    reverse(all(B));

    vector<int> visited(n);
    int nPair = 0;
    rep (i, n) {
        int blue = C[i].first;
        int x2 = c[blue];
        int y2 = d[blue];
        rep (j, n) {
            int red = B[j].first;
            if (visited[red] >= 1) {
                continue;
            }

            int x1 = a[red];
            int y1 = b[red];
            if (x1 < x2 && y1 < y2) {
                visited[red] = 1;
                nPair++;
                break;
            }
        }
    }

    put(nPair);


    return 0;
}