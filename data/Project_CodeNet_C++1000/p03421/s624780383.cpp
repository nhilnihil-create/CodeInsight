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


//BELOW
//-----CODE------//


void solve(void)
{
  //https://kmjp.hatenablog.jp/entry/2018/03/11/1100
  int n,a,b;
  cin>>n>>a>>b;
  if(a + b > n + 1)
  {
    cout<<-1<<endl;
    return;
  }
  if(a*b < n)
  {
    cout<<-1<<endl;
    return;
  }
  vector<int> vec;
  int s = n - a;
  int cur = n;
  for (int i = 0; i < a; i++)
  {
    int num = min(b-1,s) + 1;
    s -= num -1;
    for (int j = 0; j < num; j++)
    {
      vec.push_back(cur - num + 1 +j);
    }
      cur -= num;  
  }
  reverse(ALL(vec));
  for (int i = 0; i < vec.size(); i++)
  {
      if(i != 0)cout<<char(32);
      cout<<vec[i];
  }
  cout<<endl;

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
