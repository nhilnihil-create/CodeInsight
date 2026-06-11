#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll a,b,q;
  cin >> a >> b >> q;
  vector<ll> s(a);
  vector<ll> t(b);
  for(int i = 0;i < a;i++)cin >> s[i];
  for(int i = 0;i < b;i++)cin >> t[i];
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  for(int i = 0;i < q;i++){
    ll x = 0;
    cin >> x;
    ll ls,lt,rs,rt;
    rs = lower_bound(s.begin(),s.end(),x) - s.begin();
    rt = lower_bound(t.begin(),t.end(),x) - t.begin();
    ls = rs - 1;
    lt = rt - 1;
    if(rs >= a)rs = pow(10,18);
    else rs = s[rs];
    if(rt >= b)rt = pow(10,18);
    else rt = t[rt];
    if(ls < 0)ls = -1 * pow(10,18);
    else ls = s[ls];
    if(lt < 0)lt = -1 * pow(10,18);
    else lt = t[lt];
    ll res = 0;
    res = pow(10,18);
    res = min(res,abs(min(ls,lt) - x));
    res = min(res,abs(max(rs,rt) - x));
    res = min(res,min(abs(x - ls),abs(x - rt)) * 2 + max(abs(x - ls),abs(x - rt)));
    res = min(res,min(abs(x - lt),abs(x - rs)) * 2 + max(abs(x - lt),abs(x - rs)));
    cout << res << endl;
  }
}