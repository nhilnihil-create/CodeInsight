#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

//素数判定
bool isPrime(int num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false;
  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2){
    if (num % i == 0) return false;
  }
  return true;
}

int main(){
  string s;
  cin >> s;
  
  int n = s.size();
  int ans = 0;
  rep(i,n-1){
    if(s[i] == s[i+1]){
      ans++;
      if(s[i] == '0') s[i+1] = '1';
      if(s[i] == '1') s[i+1] = '0';
    }
  }
  
  cout << ans << endl;
}