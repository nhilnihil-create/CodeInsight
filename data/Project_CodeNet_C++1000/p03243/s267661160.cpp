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
    
    int d3 = n/100;
    int x = 100 * d3 + 10 * d3 + d3;
    if (x >= n) {
        put(x);
    }
    else {
        put(100 * (d3 + 1) + 10 * (d3 + 1) + d3 + 1)
    }
    return 0;
}