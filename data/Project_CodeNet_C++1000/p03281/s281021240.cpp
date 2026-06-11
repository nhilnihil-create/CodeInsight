#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  int ans = 0;
  int count = 0;
  for(int i = 1; i <= n; i++){
    if(i % 2 == 1){
      for(int j = 1; j <= i; j++){
        if(i % j == 0){
          count++;
        }//if
      }//for
      if(count == 8){
        ans++;
      }//if
    }//if
    count = 0;
  }//for
  
  cout << ans << endl;
}