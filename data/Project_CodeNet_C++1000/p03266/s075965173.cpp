#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}



int main(){
	ll N, K;//計算に使うんでllにします
	cin >> N >> K;

	// a+b, b+c, c+a　のすべてが0 (mod K)になればよい
	//→ a, b, cがすべて0 (mod K) あるいは K/2 (mod K)となる場合のみを計算すればよい
	// K/2の方はKが偶数でないとa, b, cが整数でなくなる
	ll ans = (N / K) * (N / K) * (N / K);//()をつけないと左から計算されていき, 例えば2回目のKで割るときにおかしくなる
	if(K%2 == 0) ans += ((N+K/2)/K) * ((N+K/2)/K) * ((N+K/2)/K); 
	cout << ans << endl;
	return 0;
}

