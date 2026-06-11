#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
#define vcin(a)                          \
    for (int i = 0; i < (a).size(); i++) \
        cin >> (a)[i];

int main()
{
    int N, K;
    cin >> N >> K;
    vll a(N), s(N+1);
    rep(i, N)
    {
        cin >> a[i];
    }
    partial_sum(a.begin(),a.end(), s.begin()+1);
    unordered_map<ll, int> sums;
    vll sumsInt;
    for (size_t i = 0; i < N+1; i++)
    {
        for (size_t j = i + 1; j < N+1; j++)
        {
            sums[(s[j] - s[i])]++;
            sumsInt.push_back(s[j]-s[i]);
        }
//        sums[s[i]]++;
//        sumsInt.push_back(s[i]);
    }
//    sumsInt.push_back(s.back());
//    sums[(s.back())]++;
    sort(all(sumsInt));
    bitset<60> ans = 0;
    for (int digit = 60; digit >= 0; digit--)
    {
        int cnt = 0;
        for (auto &&i : sums)
        {
            if ((i.first & (1LL<<digit)))
                cnt += i.second;
        }
        if (cnt >= K)
        {
            for (auto &&i : sums)
            {
                if (!(i.first & (1LL<<digit)))
                {
                    i.second=0;
                }
            }

            ans[digit] = 1;
        }
    }
    cout << ans.to_ullong() << endl;
    return 0;
}
