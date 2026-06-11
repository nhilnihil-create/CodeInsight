#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;

long long npow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

signed _main(){
  int A,B; cin >> A >> B;
  bitset<40> ans;
  rep(i,40){
    if(i==0){
      if(A%2==0 && B%2==0){
        ans[i]=((B-A)/2)%2;
      }
      else ans[i]=((B-A+2)/2)%2;
    }
    else{
      int tmp=0;
      int N=npow(2,i);
      int num1=(N+A)/N;
      int num2=(N+B)/N;
      if(num1==num2){
        if(num1%2==0){
          tmp=B-A+1;
        }
      }
      else{
        if(num1%2==0){
          tmp+=N-(N+A)%N;
        }
        if(num2%2==0){
          tmp+=(N+B)%N+1;
        }
      }
      ans[i]=tmp%2;
    }
  }
  cout << ans.to_ullong() << endl;
  return 0;
}
