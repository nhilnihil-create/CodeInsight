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
    ll d, g;
    cin >> d >> g;

    vector<int> p(d), c(d);
    rep(i, d) cin >> p[i] >> c[i];
    
    // 全問正解
    vector<int> nums(d);
    rep(i, 10) nums[i] = i;
    int best = 1e8;
    do {
        ll G = g; 
        int sum = 0;
        rep(_i, d) {
            int i = nums[_i];
            int C1 = 100 * (i+1) * p[i];
            int C2 = C1 + c[i];
            if (G >= C1) {
                G -= C2;
                sum += p[i];
            }
            else {
                int u = (100 * (i+1));
                int np = (G + u - 1) / u;
                G -= np * u;
                sum += np;
            }
            if (G <= 0) {
                break;
            }
        }
        best = min(sum, best);
    } while (next_permutation(nums.begin(), nums.end()));

    put(best);

    return 0;
}