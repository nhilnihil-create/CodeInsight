#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = INT_MAX;
const ll LLINF = INT64_MAX;
const double PI = acos(-1);
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; string s[3];
  cin>>n;
  for(int i=0;i<3;i++)cin>>s[i];
  int ans=0;
  for(int i=0;i<n;i++){
    map<char,int> m;
    for(int j=0;j<3;j++){
      m[s[j][i]]++;
    }
    ans+=(int)m.size()-1;
  }
  cout<<ans<<endl;
}