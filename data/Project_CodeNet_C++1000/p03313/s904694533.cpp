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


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  int l=1<<n;
  vector<int>a(l+1);
  rep(i,l)cin>>a[i];
  vector<pair<int,int>>dp(l);
  rep(i,l)
  {
    int ti=i,used=0;
    dp[i]={i,l};
    vector<int>id;
    id.push_back(0);
    id.push_back(i);
    id.push_back(l);
    while(used!=i)
    {
      int ni=((ti-1-used)&i)|used;
      id.push_back(dp[ni].first);
      id.push_back(dp[ni].second);
      used|=i-ni;
    }
    sort(all(id));
    id.erase(unique(all(id)),id.end());
    sort(all(id),[&](int x,int y){return a[x]>a[y];});


    dp[i]={id[0],id[1]};

  }
  vector<int>res(l+1);
  //rep(i,l)cout<<dp[i].first<<dp[i].second<<endl;
  rep(i,l-1)res[i+1]=max(res[i],a[dp[i+1].first]+a[dp[i+1].second]);
  rep(i,l-1)cout<<res[i+1]<<"\n";
  cout<<endl;

  return 0;

}
