
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


void solve(void)
{
  //詰める動作を最後にすると考えると捨てる動作と同一視できる。左から取る回数　右から取る回数を全探索し、余ったK回捨てる動作を行う。以上をシュミレーション 
  int N,K;cin>>N>>K;
  deque<int> inq;
  for (int i = 0; i < N; i++)
  {
    int X;cin>>X;
    inq.push_back(X); 
  }
  int res = -1*INF;
  for (int a = 0; a <= min(N,K); a++)
  {
    for (int b = 0; a + b <=min(N,K); b++)
    {
      auto q = inq;
      priority_queue<int, vector<int>, greater<int> > pq;
      int d = max(0LL,K - a - b);
            
      int s = 0;
      for (int i = 0; i < a; i++)
      {
        pq.push(q.front());
        s += q.front();
        q.pop_front();
      }

      for (int i = 0; i < b; i++)
      {
        pq.push(q.back());
        s+=q.back();
        q.pop_back();
      }
      
      chmax(res,s);
      
      for (int i = 0; i < d; i++)
      {
        if(pq.empty())break;
        s -=pq.top();
        chmax(res,s);
        pq.pop();  
      }

      
      
    }
    
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
