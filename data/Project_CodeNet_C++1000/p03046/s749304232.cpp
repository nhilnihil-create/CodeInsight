  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   long long ll;
typedef   unsigned long long ull ;
typedef   double dll ;

#define   mp make_pair
#define   pb push_back
#define   ff first 
#define   ss second
#define   IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define   endl "\n" 
#define   pll pair<ll, ll>
#define   all(x) x.begin(), x.end()
#define   vll vector<ll> 

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll m, k;
  cin >> m >> k;
  ll maxx = (1ll<<m) - 1;
  if(k > maxx) {
    cout << -1;
    return 0;
  }
  if(m == 1) {
    if(k == 0) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << "-1" << endl;
    }
    return 0;
  }
  for(ll i = 0; i <= maxx; i++) {
    if(i == k)continue;
    cout << i << " ";
  }
  cout << k << " ";
  for(ll i = maxx; i >= 0; i--) {
    if(i == k) continue;
    cout << i << " ";
  }
  cout << k << endl;
  return 0;
} //good night.