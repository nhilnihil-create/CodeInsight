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
    int n, t, a;
    cin >> n >> t >> a;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    
    int best = -1;
    long double score = 1e8; 
    rep(i, n) {
        long double z = t - h[i] * 0.006;
        if (score > abs(z - a)) {
            score = abs(z - a);
            best = i;
        }
    }
    put(best + 1);    
    return 0;
}