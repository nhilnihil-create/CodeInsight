#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;
///vector<pair<string, int>>;

int main(){
  int n;
  ll yen;
  cin >> n >> yen;
  int check = 0;
  int x = -1, y = -1, z = -1;
  rep(i, n+1){
    rep(j, n+1){
      int senen = n-i-j;
      if(senen >= 0){
        ll money = 10000 * i + 5000 * j + 1000 * senen;
        if(money == yen) {
          x = i;
          y = j;
          z = senen;
          check = 1;
        }
        if(check) break;
      }
      if(check) break;
    }
    if(check) break;
    
  }
  
  cout << x <<" "<<y <<" "<< z<< endl;
  
}
