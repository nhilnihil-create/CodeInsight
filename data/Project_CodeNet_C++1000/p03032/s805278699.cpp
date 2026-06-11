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

// template <typename T>
// void print_pairvec(const vector<T> &v, ll num=0){
//   if(num == 0) num = (ll)v.size();
//   cout << endl; for(ll i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
// }
template <typename T>
void print_pairvec(const T &_pair, ll num=0){
  cout << endl; for(pair<ll, int> x: _pair){ cout << x.first << " " << x.second << endl;}
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

int chmax(int &a, int b){ return a = max(a, b);}
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> V(N);
  for(int i=0; i<N; i++) cin >> V[i];

  int ans = 0;
  for(int left=0; left<=N; left++){
    for(int right=0; right<=N-left; right++){
      int tmp_k = K - left - right;
      if(tmp_k < 0) continue;
      priority_queue<int, vector<int>, greater<int>> get; 
      for(int i=0; i<left; i++) get.push(V[i]);
      for(int i=0; i<right; i++) get.push(V[N-i-1]);
      for(int i=0; i<tmp_k; i++){
        if(!get.empty() && get.top() < 0) get.pop();
        else break;
      }
      int sum = 0;
      while(!get.empty()){ sum += get.top(); get.pop(); }
      // cout << " left: " << left << " right: " << right << " sum: " << sum << " ans: " << ans << endl;
      ans = max(ans, sum);
    }
  }
  cout << ans << endl;
  return 0;
}
