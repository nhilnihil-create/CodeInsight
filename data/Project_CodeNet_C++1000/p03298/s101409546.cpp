#include<bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353 
#define MEM_SIZE 101010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()


template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

void solve(void)
{
  int x;cin>>x;
  string str;cin>>str;
  string s1,s2;
  int n = str.size() /2;
  s1 = str.substr(0,n);
  s2 = str.substr(n,n);
  map<pair<string,string>,int> mp,mp2;
  for (int b = 0; b < (1<<n); b++)
  {
      vector<int> bit;
      for (int i = 0; i < n; i++)
      {
          bit.push_back((b>>i)&1);
      }
      string rs = "";
      string ls = "";
      for (int i = 0; i < n; i++)
      {
        if(bit[i] == 1)rs.push_back(s1[i]);
        else ls.push_back(s1[i]);
      }
      mp[make_pair(rs,ls)]++;
  }
  // DEBUG(s1,s2);
  reverse(ALL(s2));
  for (int b = 0; b < (1<<n); b++)
  {
      vector<int> bit;
      for (int i = 0; i < n; i++)
      {
          bit.push_back((b>>i)&1);
      }
      string rs = "";
      string ls = "";
      for (int i = 0; i < n; i++)
      {
        if(bit[i] == 1)rs.push_back(s2[i]);
        else ls.push_back(s2[i]);
      }
      mp2[make_pair(rs,ls)]++;
  }
  int res = 0;
  for (auto &&i : mp)
  {
    // if(i.first.first == "" || i.first.second == "")continue;
    
    res += i.second*mp2[i.first];
  }
  cout<<res<<endl;
  
  return;
}

int32_t main(int32_t argc, const char *argv[])
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cout << std::fixed;
  std::cout << std::setprecision(11);
  solve();

  return 0;
}
