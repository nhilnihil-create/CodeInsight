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
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> v;
    rep(i, k) {
        if (a + i <= b) {
            v.push_back(a + i);
        }
    }
    rep(i, k) {
        if (a <= b - (k - 1) + i) {
            v.push_back(b - (k - 1) + i);
        }
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());

    rep(i, v.size()) cout << v[i] << endl;
    return 0;
}