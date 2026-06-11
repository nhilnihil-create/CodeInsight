#include <iostream>
#include <cstring>
using namespace std;
typedef pair<char,char> P;
int n,q;
string s;
P td[200005];
int ans;
int ans2;


bool cimu(int pos, bool swi) {
  for(int i = 0; i < q; i++) {
    if(td[i].first != s[pos]) continue;
    if(td[i].second == 'L') pos--;
    else pos++;
    if(pos < 0 && swi) return true;
    else if(pos >= n && !swi) return true;
  }

  return false;
}
  
void solve() {
  int l = -1, r = n;
 
  while(r - l > 1) {
    int mid = (l + r) / 2;
    // cout << "l1 = "<<l <<"  r1 = "<<r<< endl;
    if(cimu(mid,true) == true) l = mid;
    else r = mid;
  }
  ans = l;
  //  cout << ans << endl;
  l = -1; r = n;
  while(r - l > 1) {
    int mid = (l + r) / 2;
    //cout << "l2 = "<<l <<"  r2 = "<<r<< endl;
    if(cimu(mid,false) == true) r = mid;
    else l = mid;
  }
  ans2 = n - l;

  return;
}
  
int main() {
  cin >> n >> q >> s;

  for(int i = 0; i < q; i++) cin >> td[i].first >> td[i].second;

  solve();
  cout << n - (ans + ans2) << endl;
}
  
  
