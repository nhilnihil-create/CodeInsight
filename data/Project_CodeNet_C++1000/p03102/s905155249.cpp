#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    rep(i, m) cin >> b[i];
    vector<int> a(m);
    int cnt = 0;
    rep(j, n) {
        rep(i, m) cin >> a[i];
        int v = c;
        rep(i, m) {
            v += a[i] * b[i];
        }
        if (v > 0) {
            cnt++;
        }
    }
    put(cnt)

    return 0;
}