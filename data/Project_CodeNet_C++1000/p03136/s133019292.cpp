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
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    
    int maxL = 0;
    rep(i, n) maxL = max(maxL, l[i]);
    int sum = 0;
    rep(i, n) sum += l[i];
    yorn (maxL < sum - maxL) {

    }

    return 0;
}