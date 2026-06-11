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

#define rep(i, n) for(int i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=ll(a);i<ll(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  vector<pair<int,int>>su(n);
  rep(i,n)
  {
    ll a,b;
    cin>>a>>b;
    su[i]={b,a};
  }
  sort(all(su),greater<pair<int,int>>());
  vector<bool>used(n+1);
  int syurui=0;

  vector<int>id;
  rep(i,n)
  {
    if(!used[su[i].second]){used[su[i].second]=1;id.push_back(i);syurui++;}
  }

  vector<ll>sum1(n+1),sum2(id.size()+1);
  rep(i,n)sum1[i+1]=su[i].first+sum1[i];
  rep(i,id.size())sum2[i+1]=su[id[i]].first+sum2[i];
  int inid=upper_bound(all(id),k-1)-id.begin();
  ll res=(ll)inid*inid+sum1[k];
  inid--;
  int idx=k-1;
  int maid=1+min(k,syurui);
  repi(i,inid+2,maid)
  {
    ll tres=(ll)i*i;
    while(idx==id[inid])
    {
      inid--;
      idx--;
    }
    idx--;
    tres-=sum2[inid+1];
    tres+=sum2[i];
    tres+=sum1[idx+1];
    chmax(res,tres);
  }
  cout<<res<<endl;

  return 0;

}
