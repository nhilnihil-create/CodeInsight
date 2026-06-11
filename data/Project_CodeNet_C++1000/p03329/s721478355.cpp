#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll dfs(vl &amount, ll rem, ll cnt, ll &ans){
  if(cnt > ans){
    return -1;
  }
  
  if(amount.size() == 0){
    ans = min(ans, cnt + rem);
    return 0;
  }

  ll top = amount[amount.size() - 1];
  ll div = rem / top;
  amount.pop_back();

  ll ret = 0;

  rep_inv(i, div, -1){
    ret = dfs(amount, rem - top * i, cnt + i, ans);
    if(ret == -1) break;
  }

  amount.push_back(top);
  
  return 0;
}

int main(){
  ll N;
  cin >> N;

  ll div_6 = 1, div_9 = 1;
  priority_queue<ll, vl, greater<ll>> que;

  while(div_6 < N){
    div_6 *= 6;
    que.push(div_6);
  }
  
  while(div_9 < N){
    div_9 *= 9;
    que.push(div_9);
  }

  vl amount;
  while(!que.empty()){
    amount.push_back(que.top());
    que.pop();
  }
  
  ll ans = (ll)pow(10, 18);
  ll ret = dfs(amount, N, 0, ans);

  cout << ans << endl;
  
  return 0;
}
