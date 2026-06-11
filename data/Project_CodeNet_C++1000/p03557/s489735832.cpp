#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,f,n) for(int i=f; i<(n); i++)
int main()
{
  ll n, ans = 0;
  cin >> n;
  vector<ll> a, b, c;
  REP(i,0,n){
    int inter;
    cin >> inter;
    a.push_back(inter);
  }
  REP(i,0,n){
    int inter;
    cin >> inter;
    b.push_back(inter);
  }
  REP(i,0,n){
    int inter;
    cin >> inter;
    c.push_back(inter);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  
  
  REP(i,0,n){
    ll sita = upper_bound(c.begin(),c.end(),b[i]) - c.begin();
    ll ue = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
    ans += (n - sita)*ue;
  }
  cout << ans << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}