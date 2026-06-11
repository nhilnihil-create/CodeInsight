#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int d;
  ll g;
  cin >> d >> g;
  vector<P> p(d);
  int ans = 0;
  rep(i,d){
    cin >> p[i].first;
    cin >> p[i].second;
    ans += p[i].first;
  }

  rep(i,1<<(d+1)){
    ll score = 0;
    int cnt = 0;
    rep(j,d){
      if((i & 1<<j) == (1<<j)){
        score += (j+1)*100 * p[j].first + p[j].second;
        cnt += p[j].first;
      }
    }
    if(score < g){
      int j = d-1;
      while(score < g && j >= 0){
        if((i & 1<<j) != (1<<j)){
          int k=1;
          while(score < g && k<p[j].first){
            score += (j+1)*100;
            cnt++;
            k++;
          }
        }
        j--;
      }
    }
    if(cnt < ans && score >= g) ans = cnt;
  }
  cout << ans << endl;

  return 0;
}
