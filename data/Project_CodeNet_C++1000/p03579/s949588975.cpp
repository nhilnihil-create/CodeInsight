#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using db = double;
using vll = vector<long long>;
using vvll = vector<vll>;
using vst = vector<st>;
using vchar = vector<char>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
ll mod = 1000000007;

vll color;
bool dfs(vvll &graph, ll now, ll cur = 0){
  color[now] = cur;
  vrep(next, graph[now]){
    if(color[next] == -1){
      if(!dfs(graph, next, 1 - cur)) return false;
    }
    else{
      if(cur == color[next]) return false;
    }
  }
  return true;
}

int main(){
  ll n, m;
  cin >> n >> m;
  vvll graph(n); // あとでここを確認
  color.assign(n, -1);
  rep(i, 0, m){
    ll a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  if(dfs(graph, 0, 0)){
    ll black = 0, white = 0;
    vrep(i, color){
      if(i == 0) black++;
      else white++;
    }
    cout << white * black - m << endl;
  }
  else cout << n * (n - 1) / 2 - m << endl;
}