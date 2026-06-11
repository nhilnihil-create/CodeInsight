#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int keta(int x){
  int ans = 0;
  while (x > 0){
    x /= 10;
    ans++;
  }
  return ans;
}

int judge(int x){
  vector<int> res(3);
  while(x > 0){
    if (x % 10 == 3) res[0] = 1;
    if (x % 10 == 5) res[1] = 1;
    if (x % 10 == 7) res[2] = 1;
    x /= 10;
  }
  if (res[0] && res[1] && res[2]) return 1;
  return 0;
}

int main(){
  int n;
  cin >> n;
  vector<int> a;
  a.pb(3); a.pb(5); a.pb(7);

  rep(i, 9){
    rep(j, a.size()){
      if (keta(a[j]) == i){
        a.pb(a[j] * 10 + 3);
        a.pb(a[j] * 10 + 5);
        a.pb(a[j] * 10 + 7);
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < a.size() && a[i] <= n; i++){
    if (judge(a[i])) ans++;
  }
  cout << ans << endl;
}