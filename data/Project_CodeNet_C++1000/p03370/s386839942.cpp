#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  int ans = 0;
  vector<int> d(n);
  for(int i = 0; i < n; i++){
    cin >> d[i];
    x -= d[i];
    ans++;
  }
  int m = *min_element(d.begin(),d.end());
  ans += x / m;
  cout << ans << endl;
}