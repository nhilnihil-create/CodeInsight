#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using edge = struct {int to; ll cost;};

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)
#define INF (1 << 29)


//long C(long n, long r);
//long long gcd(long long a, long long b);
//long long lcm(long long a, long long b);

void solve()
{
    int n;
    cin >> n;
    list<pair<int, int>> red, bule;
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        red.push_back(make_pair(a, b));
    }
    REP(i, n) {
        int c, d;
        cin >> c >> d;
        bule.push_back(make_pair(c, d));
    }
    bule.sort();
    int ans = 0;
    for(auto b : bule){
        int y = -1;
        auto removeItem = red.end();
        for(auto itr = red.begin(); itr != red.end(); ++itr){
            if(b.first > (*itr).first && b.second > (*itr).second) {
                if(y < (*itr).second) {
                    y = (*itr).second;
                    removeItem = itr;
                }
            }
        }
        if(removeItem != red.end()) {
            red.erase(removeItem);
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}