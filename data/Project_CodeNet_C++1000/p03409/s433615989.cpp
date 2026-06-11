#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
//#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;


int main() {
  int N; cin >> N;
  vector<pair<int, int>> red(N);
  rep(i, 0, N) cin >> red[i].first >> red[i].second;
  vector<pair<int, int>> blue(N);
  rep(i, 0, N) cin >> blue[i].first >> blue[i].second;

  sort(blue.begin(), blue.end(), [](auto a, auto b) {
    return a.first < b.first;
  });

  int ans = 0;
  rep(i, 0, N){
    pair<int, int> maxiy = {-1, -1};
    rep(k, 0, N){
      if(blue[i].first > red[k].first && blue[i].second > red[k].second && maxiy.second < red[k].second) maxiy.first = k, maxiy.second = red[k].second;
    }
    if(maxiy.second != -1) red[maxiy.first].second = 10000, ++ans;
  }

  cout << ans << endl;

}