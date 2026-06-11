#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return __gcd(a,b); } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最小公倍数

int main() {
  int cnt[5] = {0};
  for(int i(0);i<3;i++){
    int a,b;
    cin>>a>>b;
    cnt[a]++;
    cnt[b]++;
  }
  int cnt1(0),cnt2(0);
  for(int i(0);i<5;i++){
    if(cnt[i] == 1) cnt1++;
    if(cnt[i] == 2) cnt2++;
  }
  //cout << cnt1 << " " << cnt2 << endl;
  if(cnt1 == 2 && cnt2 == 2){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}