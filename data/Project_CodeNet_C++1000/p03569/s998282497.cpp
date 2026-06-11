#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

// 最小公倍数
unsigned lcm(unsigned a, unsigned b){
    return a / gcd(a, b) * b; 
}

int main(){
  string S;
  cin >> S;
  int i = 0, j = S.length() - 1, ans = 0;
  while(j > i){
    if(S.at(i) != S.at(j)){
      ans++;
      if(S.at(i) == 'x') i++;
      else if(S.at(j) == 'x') j--;
      else {
        print(-1);
        return 0;
      }
    }else{
      i++;
      j--;
    }
  }

print(ans);
}