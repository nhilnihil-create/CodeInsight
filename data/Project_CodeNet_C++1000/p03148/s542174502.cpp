#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;
#define MOD 1000000007LL

int main(){
  ll N, K;
  cin >> N >> K;
  vector<Pll> td(N);
  for(int i = 0; i < N; i++){
    cin >> td.at(i).first >> td.at(i).second;
  }
  sort(ALL(td));
  set<int> se;
  for(int i = 0; i < N; i++){
    if(!se.count(td.at(i).first)){
      se.insert(td.at(i).first);
      td.at(i).first = se.size()-1;
    }
    else td.at(i).first = se.size()-1;
  }
  ll type = se.size();
  priority_queue<Pll> unused;
  priority_queue<Pll, vector<Pll>, greater<Pll>> used;
  for(int i = 0; i < N; i++){
    unused.push(Pll(td.at(i).second, td.at(i).first));
  }
  vll counter(type, 0);
  ll typenum = 0;
  ll sum = 0;
  ll ans = 0;
  for(int i = 0; i < K; i++){
    Pll n = unused.top(); unused.pop();
    used.push(n);
    if(counter.at(n.second) == 0) typenum++;
    counter.at(n.second)++;
    sum += n.first;
  }
  ans = sum + typenum * typenum;
  while(!used.empty()){
    ll t = used.top().second;
    ll x = used.top().first;
    used.pop();
    if(counter.at(t) == 1) continue;
    counter.at(t)--;
    sum -= x;
    while(!unused.empty()){
      ll tt = unused.top().second;
      ll xx = unused.top().first;
      unused.pop();
      if(counter.at(tt) > 0) continue;
      used.push(Pll(xx, tt));
      counter.at(tt)++;
      typenum++;
      sum += xx;
      break;
    }
    chmax(ans, sum + typenum * typenum);
  }

  cout << ans << endl;
}