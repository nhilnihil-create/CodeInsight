#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;

long long MOD = 1000000000 + 7;



int main(){
  cout << setprecision(10);
  int N,K; cin >> N >> K;

  auto pil_greator = [](pil x, pil y){
    return x.second < y.second;
  };
  auto pil_less = [](pil x, pil y){
    return x.second > y.second;
  };

  priority_queue<pil, vector<pil>, decltype(pil_greator)> pq(pil_greator);
  priority_queue<pil, vector<pil>, decltype(pil_less)> pq_second(pil_less);

  for(int i = 0; i < N; i++){
    int t; ll d; cin >> t >> d;
    pq.push(make_pair(t,d));
  }

  ll ans = 0;
  map<int,int> m;
  for(int i = 0; i < K; i++){
    pil now = pq.top();
    // cerr << "now: " << now.first << " " << now.second << endl;
    pq.pop();
    ans += now.second;
    if(m.count(now.first) == 0){
      m[now.first]++;
      continue;
    } else {
      pq_second.push(now); // 外す対象
    }
  }

  ll max_val = ans + ( m.size() * m.size() );
  // pq_second にいる人を外す
  // pq にいる人で、mapにいない人を追加する 
  
  // cerr << "change" << endl;

  while(!pq.empty()){
    pil now = pq.top();
    // cerr << "now: " << now.first << " " << now.second << endl;
    pq.pop();
    if(m.count(now.first) == 0){

      if(pq_second.empty()) break;

      pil remove = pq_second.top();
      pq_second.pop();
      ans -= remove.second;

      m[now.first] = 1;
      ans += now.second;
      ll t = m.size() * m.size();
      max_val = (max_val > ans + t ? max_val : ans + t);
    } else { 
      // 追加する必要ない
      continue;
    }
  }

  cout << max_val << endl;
}
