#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;

vector<int> check;

int
digit(ll val)
{
  int count = 0;
  while(val >= 1){
    val /= 10;
    count++;
  }
  return count;
}

int
main() 
{

  int n; cin >> n;
  vector<ll> arr(n);
  rep(i, 0, n) cin >> arr[i];

  int count = 0;
  ll min = MAX;
  ll ans = 0;
  rep(i, 0, n){
    if(arr[i] <= 0){
      count++;
      arr[i] *= -1;
    }
    ans += arr[i];
    if(arr[i] < min) min = arr[i];
  }

  if(count % 2 == 0){
    cout << ans << endl;
  } else {
    cout << ans - min * 2 << endl;
  }

}


