#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, ll num=0){
  if(num == 0) num = (ll)v.size();
  cout << endl; cout << "i=  ";for(ll i=0; i<num; i++) cout << i << "   ";cout << endl;  
  cout << "    ";
  if(is_reverse) for(ll i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<"   ";}
  else for(ll i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<"   ";}
  cout << endl;
}

template <typename T>
void print_pairvec(const vector<T> &v, ll num=0){
  if(num == 0) num = (ll)v.size();
  cout << endl; for(ll i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
}

template <typename T>
void print_vec2(const vector<vector<T>>& v){
  cout << endl; cout << "       ";
  for(ll i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(ll i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(ll j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

using LP = pair<ll, int>;
int main(){
  int H, W;
  cin >> H >> W;
  const int NUMS = 10;
  vector<vector<ll>> c(NUMS, vector<ll>(NUMS));
  for(int i=0; i<NUMS; i++){
    for(int j=0; j<NUMS; j++) cin >> c[i][j];
  }
  vector<vector<int>> A(H, vector<int>(W));
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++) cin >> A[i][j];
  }
  
  //ダイクストラで 数字iを1に変える最小コストを求める
  const ll INF = (ll)1 << 60;
  vector<ll> to1(NUMS, INF); to1[1] = 0;
  for(int i=0; i<NUMS; i++){
  // for(int i=8; i<9; i++){
    if(i==1) continue;
    vector<vector<ll>> costs(NUMS, vector<ll>(NUMS, INF));
    for(int i=0; i<NUMS; i++) costs[i][i] = 0;
    priority_queue<LP, vector<LP>, greater<LP>> pri_qu;
    pri_qu.push(LP(0, i));
    while(!pri_qu.empty()){
      ll cost = pri_qu.top().first;
      int num = pri_qu.top().second;
      pri_qu.pop();
      
      for(int j=0; j<NUMS; j++){
        if(j==num) continue;
        if(costs[num][j] <= cost + c[num][j]) continue;
        costs[num][j] = cost + c[num][j];
        pri_qu.push(LP(costs[num][j], j));
        if(j==1) to1[i] = min(to1[i], costs[num][1]);
      }
    }
  }
  ll ans = 0;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if(A[i][j] == 1 || A[i][j] == -1) continue;
      int num = A[i][j];
      ans += to1[num];
    }
  }
  cout << ans << endl;
  


  return 0;
}
