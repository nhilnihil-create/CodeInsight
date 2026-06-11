#include<bits/stdc++.h>
using namespace std;
#define int long long

#define I32_MAX 2147483647
#define I64_MAX 9223372036854775807LL
#define I64_MAX2 1223372036854775807LL
#define INF I64_MAX2
#define MOD 1000000007
// #define MOD 998244353 
#define MEM_SIZE 100010
#define DEBUG_OUT true
#define ALL(x) (x).begin(), (x).end()

template<typename T> void DEBUG(T e){if(DEBUG_OUT == false)return; std::cout << e <<" ";}
template<typename T> void DEBUG(const std::vector<T>& v){if(DEBUG_OUT == false)return;for(const auto& e : v){std::cout<< e << " "; } std::cout << std::endl;}
template<typename T> void DEBUG(const std::vector<std::vector<T> >& vv){if(DEBUG_OUT == false)return;for(const auto& v : vv){ DEBUG(v); } }
template<class T,class... Ts> void DEBUG(T d, Ts... e){if(DEBUG_OUT == false)return;DEBUG(d);DEBUG(e...);}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; abort();}}
template< typename T1, typename T2 > inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template< typename T1, typename T2 > inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

 

//SOLVE
void solve(void)
{
  int N;cin>>N;
  vector<map<int,int> > mp (2);
  for (int i = 0; i < N; i++)
  {
    int X;cin>>X;
    mp[i%2][X]++;
  }
  vector<vector<pair<int,int > > > mp2(2);
  for (auto &&i : mp[0])
  {
    mp2[0].push_back(make_pair(i.second,i.first));
  }
  for (auto &&i : mp[1])
  {
    mp2[1].push_back(make_pair(i.second,i.first));
  }
  sort(ALL(mp2[0]));
  reverse(ALL(mp2[0]));

  sort(ALL(mp2[1]));
  reverse(ALL(mp2[1]));
  if(mp2[0].begin()->second != mp2[1].begin()->second)
  {
    cout<<N - mp2[0].begin()->first - mp2[1].begin()->first;
  }
  else
  {
    int E1 = mp2[0].begin()->first ;
    int E2;
    int O1 =  mp2[1].begin()->first;
    int O2;
    // DEBUG(E1,O1);
    if(mp2[0].size() == 1)
    {
      E2 = 0;
    }
    else
    {
      auto itr = mp2[0].begin();
      itr++;
      E2  = itr->first;
    }

    if(mp2[1].size() == 1)
    {
      O2 = 0;
    }
    else
    {
      auto itr = mp2[1].begin();
      itr++;
      O2  = itr->first;
    }
      
     cout<<N - max(O1 +E2 ,O2 +E1)<<endl;
  
  }

  
  

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
