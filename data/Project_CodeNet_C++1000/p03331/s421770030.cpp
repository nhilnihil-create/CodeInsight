#include <bits/stdc++.h>
#define pb push_back
#define vt vector
#define ll long long
using namespace std;

const int INF = 1e9 +5;
const ll LLINF = 1e18 +5;

int i4[4] = {1,0,-1,0};
int j4[4] = {0,1,0,-1};

int digitSum(int n)
{
    int ret = 0;
    while(n)
    {
        ret += n%10;
        n /= 10;
    }
    return ret;
}
void solve()
{
    int n;
    cin >> n;
    int ans = INF;
    for(int i = 1; i < n;i++)
    {
        ans = min(ans,digitSum(i)+digitSum(n-i));
    }
    cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
solve();

  return 0;
}
