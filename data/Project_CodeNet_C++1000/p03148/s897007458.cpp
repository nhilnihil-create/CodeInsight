#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;

  vector<pair<long long, int>> dt(N);
  for(int i = 0; i < N; i++){
    int t;
    long long d;
    cin >> t >> d;
    t--;
    dt[i] = make_pair(d, t);
  }
  sort(dt.rbegin(), dt.rend());

  /*
  for(auto x: dt){
    cout << x.second << '\t' << x.first << endl;
  }
  */

  long long d_sum = 0;
  vector<bool> checked(N, false);
  int t_cnt = 0;
  multiset<long long> dups;
  for(int i = 0; i < K; i++){
    d_sum += dt[i].first;
    if(!checked[dt[i].second]){
      t_cnt++;
      checked[dt[i].second] = true;
    }else{
      dups.insert(dt[i].first);
    }
  }

  long long ans = d_sum + t_cnt * t_cnt;
  for(int i = K; i < N; i++){
    //cout << i << endl;
    //cout << dups.size() << endl;
    if(dups.size() == 0){
      break;
    }
    if(!checked[dt[i].second]){
      auto dup_min = dups.begin();
      d_sum -= *dup_min;
      dups.erase(dup_min);
      d_sum += dt[i].first;
      t_cnt++;
      checked[dt[i].second] = true;
      ans = max(ans, d_sum + t_cnt * t_cnt);
    }
  }
  cout << ans << endl;
}

