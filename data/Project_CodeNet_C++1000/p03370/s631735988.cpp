#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n, x; cin >> n >> x;
  vector<int> m(n);
  int min_m = 200000;
  for(int i = 0; i < n; i++){
  	int m; cin >> m;
    x -= m;
    min_m = min(min_m, m);
  }
  
  int ans = n;
  ans += (x / min_m);
  cout << ans << endl;
  
    return 0;
}