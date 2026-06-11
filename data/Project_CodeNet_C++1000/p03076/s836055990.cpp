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
    vector<int> v(5);
    rep(i, 5) cin >> v[i];
    int sum = 0;
    int best = 10;
    rep(i, 5) {
        sum += (v[i] + 9) / 10 * 10;
        if (1 <= v[i] % 10 && best > v[i] % 10) {
            best = v[i] % 10;
        }
    }

    if (best <= 9) {
        sum -= 10 - best;
    }
    put(sum)
    
    return 0;
}