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
    int n, m;
    cin >> n >> m;

    vector<int> x(m);
    rep(i, m) cin >> x[i];

    if (n >= m) {
        put(0);
        return 0;
    }

    sort(all(x));

    vector<int> l(m - 1);
    rep(i, m - 1) l[i] = x[i+1] - x[i];
    sort(all(l));
    int sum = 0; 
    rep(i, m - n) sum += l[i];
    put(sum);

    return 0;
}