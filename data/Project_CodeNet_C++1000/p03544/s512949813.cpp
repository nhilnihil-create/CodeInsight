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
signed main()
{
    int n;
    cin >> n;
    
    vector<ll> l(90);
    l[0] = 2;
    l[1] = 1;
    for (int i = 2; i <= n; i++) {
        l[i] = l[i - 1] + l[i - 2];
    }
    put(l[n]);

    return 0;
}