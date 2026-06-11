#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


struct b{int w,s,v;};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vector<b>bs(n);
  rep(i,n)
  {
    cin>>bs[i].w>>bs[i].s>>bs[i].v;
  }
  sort(all(bs),[](b p,b q){if(p.s+p.w!=q.s+q.w)return p.s+p.w<q.s+q.w;return p.s<q.s;});
  vector<ll>dp(20001,-1);
  dp[0]=0;
  rep(i,n)
  {
    for(int j=bs[i].s;j>=0;j--)
    {
      if(dp[j]==-1)continue;
      chmax(dp[j+bs[i].w],dp[j]+bs[i].v);
    }
  }
  auto res=(*max_element(all(dp)));
  cout<<res<<endl;
  return 0;

}
