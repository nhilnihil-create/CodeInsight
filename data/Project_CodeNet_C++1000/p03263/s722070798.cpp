#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll h, w;
  cin >> h >> w;
  
  vector<vector<ll>> a(h, vector<ll>(w));
  for (ll i = 0; i < h; i++){
    for (ll j = 0; j < w; j++){
      cin >> a[i][j];
    }
  }

  vector<string> ss(0);
  deque<string> t;

  ll b = -1;
  for (ll i = 0; i < h; i++){
    if (i % 2 == 0){
      for (ll j = 0; j < w; j++){
        if (b == -1 && a[i][j] % 2 == 1){
          b = 1;
        }
        else if (b == 0 && a[i][j] % 2 == 1){
          b = 1;
        }
        else if (b == 1 && a[i][j] % 2 == 1){
          while (!t.empty()){
            ss.emplace_back(t.back());
            t.pop_back();
          }
          b = 0;
        }

        if (b == 1 && j != w - 1){
          t.push_front(to_string(i + 1) + " " + to_string(j + 1) + " " + to_string(i + 1) + " " + to_string(j + 2));
        }
      }
      if (b == 1){
        t.push_front(to_string(i + 1) + " " + to_string(w) + " " + to_string(i + 2) + " " + to_string(w));
      }
    }
    else {
      for (ll j = w-1; j >= 0; j--){
        if (b == -1 && a[i][j] % 2 == 1){
          b = 1;
        }
        else if (b == 0 && a[i][j] % 2 == 1){
          b = 1;
        }
        else if (b == 1 && a[i][j] % 2 == 1){
          while (!t.empty()){
            ss.emplace_back(t.back());
            t.pop_back();
          }
          b = 0;
        }

        if (b == 1 && j != 0){
          t.push_front(to_string(i + 1) + " " + to_string(j + 1) + " " + to_string(i + 1) + " " + to_string(j));
        }
      }
      if (b == 1){
        t.push_front(to_string(i + 1) + " " + to_string(1) + " " + to_string(i + 2) + " " + to_string(1));
      }
    }
  }

  cout << ss.size() << endl;
  for (auto s : ss){
    cout << s << endl;
  }

  return 0;
}
