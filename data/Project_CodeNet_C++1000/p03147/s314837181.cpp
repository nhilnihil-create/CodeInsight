#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> flowers(n);
  rep(i, n) cin >> flowers[i];
  int cnt = 0;
  for(int i=1; i<=100; i++){
    bool s = false;
    rep(j, n){
      if(flowers[j] >= i) s = true;
      else{
        if(s){
          cnt++;
          s = false;
        }
      }
    }
    if(s) cnt++;
  }
  cout << cnt << endl;
  return 0;
}