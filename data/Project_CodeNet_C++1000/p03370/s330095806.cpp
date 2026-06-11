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
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    rep(i, n) cin >> m[i];
    
    int sum = 0;
    rep(i, n) sum += m[i];
    int minM = 1e8;
    rep(i, n) minM = min(minM, m[i]);
    int r = x - sum;

    int ans = n + r / minM;
    put(ans)

    return 0;
}