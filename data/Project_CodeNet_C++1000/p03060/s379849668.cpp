#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    
    int sum = 0;
    rep(i, n) {
        if (v[i] - c[i] > 0) {
            sum += v[i] - c[i];
        }
    }
    put(sum);
    return 0;
}