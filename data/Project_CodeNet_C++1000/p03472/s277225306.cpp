#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

class ab{
public:
  ll a, b, i;
  bool operator<(const ab &another) const{
    return b < another.b;
  }
};

void solve(){
  ll n, h, maxai = 0, maxaa, maxab, ans = 0; cin >> n >> h;
  vector<ab> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i].a >> v[i].b;
    v[i].i = i;
    if(v[maxai].a < v[i].a){
      maxai = i;
      maxaa = v[i].a;
      maxab = v[i].b;
    }
    else if(v[maxai].a == v[i].a && v[maxai].b <= v[i].b){
      maxai = i;
      maxaa = v[i].a;
      maxab = v[i].b;
    }
  }
  sort(v.begin(), v.end());
  bool flag = false;
  for(int i = n - 1; v[i].b > maxaa && h > 0 && i >= 0; i--){
    if(v[i].i == maxai) flag = true;
    if(flag == true){
      if(h - maxab <= 0){
        h -= maxab;
        ans++;
        continue;
      }
    }
    if(v[i].i == maxai) continue;
    h -= v[i].b;
    ans++;
    //cout << h << " " << v[i].a << " " << v[i].b << ans << endl;
  }
  if(h > 0){
    ans++;
    if(h - maxab > 0) ans += (h - maxab + maxaa - 1) / maxaa;
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
