#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
const ll mod = 1e9 + 7;
const ll inf = 1e12;
const double pi = 3.141592;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> soinsu(101);
    auto soinsubunkai = [&](int n) {
        int tmp = n;
        for (int i = 2; i <= n; i++)
        {
            if (tmp%i)
                continue;
            while(tmp%i==0 && tmp >= 1){
                soinsu[i]++;
                tmp /= i;
            }
        }
    };
    rep1(i, n + 1) soinsubunkai(i);
    auto f = [&](int len) {
        return count_if(soinsu.begin(), soinsu.end(), [&](int x) -> bool { return x >= len; });
    };
    int ans = f(74) + f(24) * (f(2) - 1) + f(14) * (f(4) - 1) + f(4) * (f(4) - 1) * (f(2) - 2) / 2;
    cout << ans << "\n";
    return 0;
}