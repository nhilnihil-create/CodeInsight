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
 
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
int main() {
  string S;
  cin >> S;
  int N = S.size();
  ll black = 0;
  ll ans = 0;
  for(int i = 0;i < N;i++){
    if(S[i] == 'B'){
      black++;
    }
    else{
      ans += black;
    }
  }
  cout << ans << endl;
}