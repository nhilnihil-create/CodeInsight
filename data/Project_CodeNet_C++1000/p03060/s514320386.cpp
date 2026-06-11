#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n;
  cin >> n;
vector<int> V(n);
vector<int> C(n);
  rep(i,n) cin >> V.at(i);
  rep(i,n) cin >> C.at(i);
int ans;
rep(i,n){
  int d = V.at(i)-C.at(i);
  if(d > 0) ans += d;
}
cout << ans << endl;

}
  
