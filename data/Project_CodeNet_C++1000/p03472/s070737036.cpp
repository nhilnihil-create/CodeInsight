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
  ll n,h;
  cin >> n >> h;
  vector<pair<ll,ll>> katana;
  ll th = 0;
  for(int i = 0;i < n;i++){
    ll a,b;
    cin >> a >> b;
    th += b;
    katana.push_back(make_pair(a,0));
    katana.push_back(make_pair(b,1));
  }
  ll res = 0;
  sort(katana.begin(),katana.end());
  ll now = 0;
  for(int i = katana.size() - 1;i >= 0;i--){
    if(katana[i].second == 1){
      now += katana[i].first;
      res++;
      if(h <= now){
        break;
      }
    }
    else{
      res += (h - now) / katana[i].first;
      if((h - now) % katana[i].first != 0)res++;
      break;
    }
  }
  cout << res << endl;
}