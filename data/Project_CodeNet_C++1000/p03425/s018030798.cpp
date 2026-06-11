#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1e+18;
int iINF = 1e9;

int 
main()
{
  int N; cin >> N;
  vector<ll> arr(5);
  rep(i, 0, N){
    string s; cin >> s;
    char ini = s[0];
    if('M' == ini) arr[0] += 1;
    if('A' == ini) arr[1] += 1;
    if('R' == ini) arr[2] += 1;
    if('C' == ini) arr[3] += 1;
    if('H' == ini) arr[4] += 1;
  }

  ll ans = 0;
  rep(i, 0, 3){
    rep(j, i + 1, 4){
      rep(k, j + 1, 5){
        ans += arr[i] * arr[j] * arr[k];
      }
    }
  }

  cout << ans << endl;

}