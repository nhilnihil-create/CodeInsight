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
#include <stack>



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
  int n;cin>>n;
  vector<int>id(n),a(n);
  rep(i,n)cin>>a[i];
  int maxid=0;
  rep(i,n)if(abs(a[maxid])<abs(a[i]))maxid=i;
  vector<pair<int,int>>res;
  rep(i,n)
  {
    res.push_back({maxid+1,i+1});
  }
  sort(all(id),[&](int p,int q){return a[p]<a[q];});
  if(a[maxid]<0)
  {
    rep(i,n-1)
    {
      res.push_back({n-i,n-i-1});
    }
  }
  else
  {

      rep(i,n-1)
      {
        res.push_back({i+1,i+2});
      }
  }
  cout<<res.size()<<"\n";
  for(auto t:res)cout<<t.first<<" "<<t.second<<"\n";
  cout<<endl;


  return 0;

}
