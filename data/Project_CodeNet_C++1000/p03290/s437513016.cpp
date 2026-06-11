#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int
main() 
{
  int D; cin >> D;
  ll G; cin >> G;
  vector<vector<ll>> point(D);
  rep(i, 0, D){
    ll p; cin >> p;
    ll c; cin >> c;
    point[i].push_back((i + 1) * 100);
    point[i].push_back(p);
    point[i].push_back((i + 1) * 100 * p + c);
  }

  //sort(point.begin(), point.end(), [](const vector<long long>&alpha,const vector<long long> &beta){return alpha[2] > beta[2];});

  ll ans = INF;
  for(int bit = 0; bit < (1 << D); ++bit){
    ll tmp_sum = G;
    ll tmp_ans = 0;
    for(int i = 0; i < D; i++){
      if(bit & (1 << i)){
       tmp_sum -= point[i][2]; 
       tmp_ans += point[i][1];
      }
    }
    if(tmp_sum > 0){
      ll tmp_index = -1;
      rep(i, 0, D){
        if(!(bit & (1 << i))) tmp_index = i;
      }
      if(tmp_index != -1){
        rep(i, 0, point[tmp_index][1]){
          tmp_sum -= point[tmp_index][0];
          tmp_ans++;
          if(tmp_sum <= 0) break;
        }
      }
    }
    if(ans > tmp_ans && 0 >= tmp_sum) ans = tmp_ans;
  }

  cout << ans << endl;

}


