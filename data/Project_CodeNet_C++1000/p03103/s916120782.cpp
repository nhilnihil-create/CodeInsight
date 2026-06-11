#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  ll n, m;
  cin >> n >> m;
  ll a, b;
  vector<pair<ll,ll>> shop;

  for(int i=0; i<n; ++i){
    cin >> a >> b;
    shop.push_back({a, b});
  }

  sort(shop.begin(), shop.end());

  ll sum = 0;
  for(auto& i: shop){
    sum += i.first * min(m, i.second);
    m -= min(m, i.second);
  }
  cout << sum << endl;
}