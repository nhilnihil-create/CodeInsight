#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  ll n, hp;  cin >> n >> hp;
  vector<pair<ll, ll>> sword(n);
  for(int i=0; i<n; i++){
    cin >> sword[i].first >> sword[i].second;
  }
    

  sort(sword.begin(), sword.end());
  vector<ll> poi;
  for(int i=0; i<n-1; i++)
    if(sword[n-1].first<sword[i].second) poi.push_back(sword[i].second);
  
  poi.push_back(sword.back().second);
  sort(poi.begin(), poi.end(), greater<ll>());
  ll cnt=0;
  
  while(0<hp && cnt<poi.size()){
    hp -= poi[cnt];   cnt += 1;
  }

  if(0<hp)
    cnt += hp/sword.back().first + min(1LL, hp%sword.back().first);
  
  cout << cnt << endl;  

  
}
