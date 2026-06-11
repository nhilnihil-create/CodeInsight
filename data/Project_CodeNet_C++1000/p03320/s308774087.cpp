#include <bits/stdc++.h>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1000000000000000
#include <iomanip>
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,ll> p;
constexpr int MOD = 1000000007;

void print(const std::vector<int>& v)
{
  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}

ll f(ll n){
  ll res = 0;
  while(n>0){
    res += n%10;
    n/= 10;
  }
  return res;
}

double g(ll n){
  return (double)(n)/f(n);
}

int main ()
{
  vector<ll> res;
  ll base = 1;
  for (int i = 0; i < 15; i++)
  {
    for (int j = 1; j < 150; j++)
    {
      res.push_back(base * (j+1) - 1);
    }
    base *= 10;
  }
  sort(res.begin(),res.end());
  res.erase(unique(res.begin(),res.end()),res.end());

  REP(i,res.size()){
    for (ll j = i; j < res.size(); j++)
    {
      if(g(res[i])>g(res[j])){
        res.erase(res.begin()+i--);
        break;
      }
    }
  }

  ll K;cin>>K;
  REP(i,K){
    cout<<res[i]<<endl;
  }
  return 0;
}