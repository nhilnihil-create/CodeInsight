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

void rerio(int hp, string s){
    if(hp == 0) print(s);
    else{
        for(char c = 'a'; c <= 'c'; c++) rerio(hp -1, s + c);
    }
}

int main(){
    ll N;
    cin >> N;
    if(N == 1 || N == 2) {
        print(0);
        return 0;
    }
    ll sum = 0;
    for(ll i = 1; N >= i * i; i++){
        ll x = (N / i) - 1;
      	// print(x);
        if(N / x == N % x ) sum += x;
        if(N / i == N % i ) sum += i;
    }
    print(sum);

}
