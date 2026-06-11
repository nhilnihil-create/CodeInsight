#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using P = pair<int, int>;
const int INF = 1001001001;

int imos[100005];
vector<P> tv[30];

int main(void){
  int n, c;
  cin >> n >> c;
  REP(i, n){
    int s, t, ch;
    cin >> s >> t >> ch;
    ch--;
    tv[ch].emplace_back(P(s, t));
  }
  REP(ch, c){
    if(tv[ch].empty()) continue;
    sort(ALL(tv[ch]));
    int m = tv[ch].size();
    int s = tv[ch][0].first;
    int t = tv[ch][0].second;
    FOR(i, 1, m){
      if(tv[ch][i].first == t){
        t = tv[ch][i].second;
      }else{
        imos[s-1] += 1;
        imos[t] -= 1;
        s = tv[ch][i].first;
        t = tv[ch][i].second;
      }
    }
    imos[s-1] += 1;
    imos[t] -= 1;
  }
  int ans = 0;
  int sum = 0;
  REP(i, 100005){
    sum += imos[i];
    chmax(ans, sum);
  }
  cout << ans << endl;
  return 0;
}