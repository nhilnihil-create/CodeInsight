#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;

vector<int> check;

int
main() 
{

  int n; cin >> n;
  vector<ll> arr(n);

  rep(i, 0, n) cin >> arr[i];

  ll ans = 0;
  rep(i, 0, n){
    while((arr[i] % 2) == 0){
      arr[i] /= 2;
      ans++;
    }
  }

  cout << ans << endl;

}


