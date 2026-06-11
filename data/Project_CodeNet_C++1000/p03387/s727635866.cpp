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

const ll INF = 10010001010;
const int inf = 2000000000;


typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    vector<int> N(3);
    cin >> N[0] >> N[1] >> N[2];
    sort(all(N));
    reverse(all(N));
    int ans = N[0] - N[1];
    N[2] += ans;
    N[1] = N[0];
    if ((N[0] - N[2]) % 2 == 1)
    {

        ans++;
        N[1]++;
        N[0]++;
    }
    ans += (N[0] - N[2]) / 2;
    cout << ans << endl;
}
