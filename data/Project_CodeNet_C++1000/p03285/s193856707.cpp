#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i <= (int)(n); i++)
 
int main(){
  int n, cake = 4, conuts = 7;
  cin >> n;
  for(int i = (int)(n/7); i >= 0; i--){
    rep(j, (int)(n/4)){
      if((n - (i * 7) - (j * 4)) == 0){
        cout << "Yes" << endl;
        exit(0);
      }
    }
  }
  cout << "No" << endl;
}