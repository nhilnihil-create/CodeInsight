#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <iomanip> 

using ll = long long;
using ull = unsigned long long;
using namespace std;

#define FALSE printf("false\n");
#define TRUE printf("true\n");
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i = 0;(i) < ((int)(n));++(i))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define test(a) cout<<"line:"<<__LINE__<<"["<<(#a)<<": "<<(a)<<"]"<<endl

const int INF = 1e9+7;
const ll INFL = 9*1e18;

// const int dx[4] = { 1, 0, -1, 0 };
// const int dy[4] = { 0, 1, 0, -1 };

const int dx[8] = {1, 1, 0,-1,-1,-1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0,-1,-1,-1};

int inline digit(ll num){int tmp = 0;while(num){tmp++;num/=10;}return tmp;} // 桁数
template<typename T>inline T SUM(vector<T> vec){return accumulate(all(vec),(T)0);} // vectorの中身を全部足す
template<typename T>inline T digitSum(T num){T sum = 0;while(num){sum+=num%10;num/=10;}return sum;} // 各桁の和
template<typename T>inline T gcd(T a,T b){if(b == 0)return a;return gcd(b,a%b);} // 最大公約数
template<typename T>inline T lcm(T a, T b){T g = gcd(a,b);return a/g*b;} // 最小公倍数
template<typename T>inline T power(T a,T b){T tmp=1;rep(i,b){tmp*=a;}return tmp;} // 累乗
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T>inline void print(T&& x){cout<<setprecision(32)<<x<<endl;}// 改行付き出力

// TODO: write
int main() {
  string s;cin>>s;
  vector<int> exist(26,0);
  rep(i,s.size())exist[s[i]-'a']++;
  if(s.size() < 26){
    rep(i,26)if(!exist[i]){
      s += 'a'+i;
      break;
    }
    print(s);
  }else if(s == "zyxwvutsrqponmlkjihgfedcba"){
    print(-1);
  }else{
    for(int i = 25; i >= 0;--i){
      for(char c = ++s[i];c <= 'z';c++){
        bool can = true;
        rep(j,i)if(c == s[j])can = false;
        if(can){
          print(s.substr(0,i) + c);
          return 0;
        }
      }
    }
  }
  return 0;
}