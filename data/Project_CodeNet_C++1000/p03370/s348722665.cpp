#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  int n, x, ans, min = 10e4, mi;
  cin >> n >> x;
  while(cin >> mi){
    x -= mi;
    ans++;
    if(min > mi){
      min = mi;
    }
  }
  cout << ans + (int)(x / min) << endl;
}