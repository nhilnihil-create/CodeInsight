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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i, m) cin >> a[i];

    int sum0 = 0, sum1 = 0;

    rep(i, m) {
        if (a[i] < x) {
            sum0 += 1;
        }
        else {
            sum1 += 1;
        }
    }

    put(min(sum0, sum1))
    
    return 0;
}