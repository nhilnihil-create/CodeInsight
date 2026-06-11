#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
  ll n;  cin >> n;
  if(n == 0){cout << 0 << endl; return 0;}
  
  string ans;
  while(n != 1){
    //cerr << n << endl;
    if(n < 0){
      if(n % 2 == 0){
        n = - n / 2;
        ans.push_back('0'); 
      }else{
        n = - (n-1) / 2;
        ans.push_back('1');
      }
    }else{
      if(n % 2 == 0){
        n = - n / 2;
        ans.push_back('0');
      }else{
        n = - (n-1) / 2;
        ans.push_back('1');
      }
    }
  }
  ans.push_back('1');
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
