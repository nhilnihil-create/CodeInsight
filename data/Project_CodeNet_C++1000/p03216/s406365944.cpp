#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
 
using ll = long long;
using P = std::pair<ll, ll>;
 
#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << #i <<" "<<i<<std::endl;
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

ll dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  std::string s;
  std::cin>>s;

  ll q;
  std::cin>>q;

  rep(_,0,q){
    ll k;
    std::cin>>k;

    ll ans=0;

    ll m_cnt=0,c_cnt=0,mnum=0;

    for(ll i=n-1;i>=0;i--){
      if(i<=n-1-k){
        if(s[i+k]=='C'){
          mnum-=m_cnt;
          c_cnt--;
        }else if(s[i+k]=='M'){
          m_cnt--;
        }
      }

      if(s[i]=='D'){
        ans+=mnum;
      }
      if(s[i]=='M'){
        m_cnt++;
        mnum+=c_cnt;
      }
      if(s[i]=='C'){
        c_cnt++;
      }
    }

    std::cout<<ans<<"\n";
  }

  return 0;
}



