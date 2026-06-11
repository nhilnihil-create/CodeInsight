#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using vb = vector<bool>;
using boolGraph = vector<vb>;
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  int a, b; cin >> a >> b;

  string white, black;
  rep(i,100) {
    white.push_back('.');
    black.push_back('#');
  }

  vector<string> GW(50), GB(50);
  rep(i,50) {
    GW[i] = white;
    GB[i] = black;
  }
  
  rep(i,a-1) GB[i/50*2+1][i%50*2] = '.';
  rep(i,b-1) GW[i/50*2][i%50*2] = '#';

  cout << "100 100" << endl;
  rep(i,50) cout << GW[i] << endl;
  rep(i,50) cout << GB[i] << endl;
  return 0;
}
