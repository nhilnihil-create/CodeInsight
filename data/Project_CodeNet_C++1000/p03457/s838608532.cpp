#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  string ans = "Yes";
  int nowh = 0, noww = 0, nowt = 0;
  while(n--){
    int t, w, h;  cin >> t >> w >> h;
    int s = t - nowt - abs(w-noww) - abs(h-nowh);  // absを忘れることがあった
    if(s >= 0 && s%2 == 0)
      noww = w, nowh = h, nowt = t;
    else
      ans = "No";
  }

  cout << ans << endl;
  return 0;
}
