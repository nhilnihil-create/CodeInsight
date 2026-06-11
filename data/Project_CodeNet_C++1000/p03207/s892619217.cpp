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
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    sort(all(p));
    int sum = 0;
    rep(i, n- 1) sum += p[i];
    sum += p[n -1] / 2;
    put(sum)
    return 0;
}