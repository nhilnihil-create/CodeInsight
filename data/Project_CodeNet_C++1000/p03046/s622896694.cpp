#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  int n, k;
  cin >> n >> k;
  if(n == 0){
    if(k == 0)
      cout << "0 0\n";
    else 
      cout << "-1\n";
  }
  else if(n == 1){
    if(k == 0)
      cout << "1 1 0 0\n";
    else
      cout << "-1\n";
  }
  else{
    if(k < (1 << n)){
      for(int i = 0; i < (1 << n); i ++ ){
        if(i != k) 
          cout << i << " ";
      }
      cout << k << " ";
      for(int i = (1 << n) - 1; i >= 0 ; i -- ){
        if(i != k)
          cout << i << " ";
      }
      cout << k << " ";
    }
    else{
      cout << -1 << "\n";
    }
  }
  return 0;
}