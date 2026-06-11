#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using Pii = pair<int, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define _GLIBCXX_DEBUG
 
constexpr int MOD = 1000000007;
const int INF = 1 << 30;
 
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a%b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }


// 各操作を行う関数を実装する
 
// AとBに共通して含まれる要素からなる集合を返す
int main(){
  int N,A,B;
  cin >>N>>A>>B;
  int sum_a = 0;
  for (int i =1;i <= N;i++){
    int c =0;
    int t =i;
    for( int j =0; j<5 ; j++){
      c += t % 10;
      t /= 10;
    }
     if(A <= c && c <= B ){
       sum_a += i;
     }
    
  }
  cout << sum_a;
}