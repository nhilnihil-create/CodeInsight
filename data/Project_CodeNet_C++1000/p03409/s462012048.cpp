#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
ll inf = 1e10;

ll gcd(ll a, ll b){
  return (b != 0) ? gcd(b, a%b) : a;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 0;
  vpii red(n), blue(n);
  rep(i, n) cin >> red[i].first >> red[i].second;
  rep(i, n) cin >> blue[i].first >> blue[i].second;
  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());
 
    
  rep(b, n){
    int maxi = -1;
    int maxy = -1;
    rep(r, n){
      if(red[r].first < blue[b].first && red[r].second < blue[b].second){
        if(red[r].second > maxy){
          maxi = r;
          maxy = red[r].second;
        }
        
      }
      else continue;
    }
    if(maxi != -1){
      red[maxi].second = -1;
      ans++;
    }
  }
  
  cout << ans << "\n";
  
}  