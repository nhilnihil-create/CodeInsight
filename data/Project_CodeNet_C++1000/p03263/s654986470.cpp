#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int
main()
{
  int H, W; cin >> H >> W;
  vector<vector<int>> arr(H);
  rep(i, 0, H){
    rep(k, 0, W){
      int a; cin >> a;
      arr[i].push_back(a);
    } 
  }

  int ans = 0;
  vector<vector<int>> display(250001);

  rep(h, 0, H){
    rep(w, 0, W - 1){
      if(arr[h][w] % 2 == 0) continue;
      display[ans].push_back(h + 1);
      display[ans].push_back(w + 1);
      display[ans].push_back(h + 1);
      display[ans].push_back(w + 2);
      ++ans;
      --arr[h][w];
      ++arr[h][w + 1];
    }
  }

  rep(h, 0, H - 1){
    if(arr[h][W - 1] % 2 == 0) continue;
      display[ans].push_back(h + 1);
      display[ans].push_back(W);
      display[ans].push_back(h + 2);
      display[ans].push_back(W);
      ++ans;
      --arr[h][W - 1];
      ++arr[h + 1][W - 1];

  }

  cout << ans << endl;

  rep(i, 0, ans){
    rep(k, 0, 4){
      cout << display[i][k];
      if(k != 3) cout << " ";
    }
    cout << endl;
  }

}
