#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;

vector<bool> IsPrime;
void sieve(ll max){
  if(max + 1 > IsPrime.size()){     // resizeで要素数が減らないように
    IsPrime.resize(max + 1, true); // IsPrimeに必要な要素数を確保
  }
  IsPrime[0] = false; // 0は素数ではない
  IsPrime[1] = false; // 1は素数ではない

  for(ll i = 2; i * i <= max; ++i) {     // 0からsqrt(max)まで調べる
    if(IsPrime[i]) {                     // iが素数ならば
      for(ll j = 2; i * j <= max; ++j) { // (max以下の)iの倍数は
        IsPrime[i * j] = false;          // 素数ではない
      }
    }
  }
}

int main(){
  int n;
  cin >> n;
  sieve(n + 1);
  vector<int> a(n + 1, 0);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
      if(i % j == 0 && IsPrime[j]){
        int tmp = i;
        while(tmp % j == 0){
          a[j]++;
          tmp /= j;
        }
      }
    }
  }
  int four = 0, two = 0, sf = 0, tf = 0,fo = 0, one = 0;
  for(int i = 1; i <= n; i++) {
    //cout << a[i] << " ";
    if(a[i] >= 74){
      sf++;
    }
    if(a[i] >= 24) {
      tf++;
    }
    if(a[i] >= 14) {
      fo++;
    }
    if(a[i] >= 4) {
      four++;
    }
    if(a[i] >= 2) {
      two++;
    }
    if(a[i] >= 1){
      one++;
    }
  }
  /*
  cout << endl;
  cout << one << " " << two << " " << four << " " << fo << " ";
  cout << tf << " " << sf << endl;
  */
  if(four <= 1 || two == 0) {
    cout << 0 << endl;
  } else {
    int ans = (two - four) * (four - 1) * four/ 2;   // 5 5 3
    ans += four * (four - 1) * (four - 2) / 2;       // 5 5 5
    ans += fo * (four - 1);            // 15 5
    ans += tf * (two - 1);             // 25 3
    ans += sf;         //75
    cout << ans << endl;
  }

  return 0;
}