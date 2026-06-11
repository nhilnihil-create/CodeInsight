#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
const ll INF = 10010001010;
const int inf = 1000034000;

typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    cout<<fixed << setprecision(16);
    int N, K;
    cin >> N >> K;
    long double ans = 0;
    for (int i = 1; i <= N;i++)
    {
        ll mul = 0;
        for (int j = i; j < K;)
        {
            j *= 2;
            mul++;
        }
        //cout << mul << endl;
        ans += (long double)(1.0 / N) * (long double)(1.0 / pow(2, mul));
        //cout << ans << endl;
    }
    cout << ans << endl;
}
