#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int D; ll G; vi p,c; 
void input()
{
    cin >> D >> G;
    p.resize(D); c.resize(D);
    for (int i = 0; i < D; ++i) cin >> p[i] >> c[i];
}

void solve()
{
    int ans = 1 << 20;
    for (int bit = 0; bit < (1 << D); ++bit){
        int num = 0;
        ll sum = 0;
        for (int i = 0; i < D; ++i){
            if (bit & (1 << i)){
                num += p[i];
                sum += 100 * (i+1) * p[i] + c[i];
            }
        }
        // cout << num << " " << sum << endl;
        if (sum >= G) ans = min (ans, num);
        else {
            for (int i = D-1; i >= 0; --i){
                if (bit & (1 << i)) continue;
                for (int j = 0; j < p[i]; ++j){
                    if (sum >= G) break;
                    num++;
                    sum += 100 * (i+1);
                }
            }
            // cout << num << " " << sum << endl;
            ans = min (ans, num);
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}