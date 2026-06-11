#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int s[1000000];
  cin >> s[0];
  
  ll ans = 0;
  ll i = 0;
  while(1){
    if(s[i] % 2 == 0){
      s[i+1] = s[i] / 2;
    }else{
      s[i+1] = s[i] * 3 + 1;
    }
    i++;
    for(int j = 0; j < i; j++){
      if(s[j] == s[i]){
        ans = i;
        break;
      }
    }
    if(ans > 0){
      break;
    }
  }//while
  
  cout << ans + 1 << endl;
}