#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  ll n;
  cin >> n;
  ll t0, x0, y0;
  cin >> t0 >> x0 >> y0;
  ll count = 0;
  ll check = 0;
  if (n == 1){
    if (abs(x0) + abs(y0) != 1) check = 1;
  }
  else{
    
    while(count < n - 1 && check == 0){
      ll t, x, y;
      cin >> t >> x >> y;
      ll time = t - t0;
      ll kyori = abs(x - x0) + abs(y - y0);
      if(time % 2 == 0 && kyori % 2 == 0 && kyori <= time){
        count++;
        x0 = x;
        y0 = y;
        t0 = t;
      }
      else if(time % 2 == 1 && kyori % 2 == 1 && kyori <= time){
        count++;
        x0 = x;
        y0 = y;
        t0 = t;
      }
      else {
        check = 1;
      }
    }
  }
    if(check == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }