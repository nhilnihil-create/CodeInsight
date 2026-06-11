#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

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

using LP = pair<ll, int>;
int main(){
	int N, M;
	cin >> N >> M;
	vector<ll> A(N);
	for(int i=0; i<N; i++) cin >> A[i];
	vector<LP> CB(M);
	for(int i=0; i<M; i++){
		ll c;  int b;
		cin >> b >> c;
		CB[i] = LP(c, b);
	}
	// 解1
	// sort(A.begin(), A.end());// 昇順ソート
	// sort(CB.rbegin(), CB.rend());// CBをCの値で降順ソート
	// vector<ll> vec;//CBの内で解放からN個取り出して並べる
	// for(int i=0; i<M; i++){
	// 	for(int j=0; j<CB[i].second; j++){
	// 		vec.push_back(CB[i].first);
	// 	}
	// 	if(vec.size() >= N) break;
	// }

	// ll ans = 0;
	// for(int i=0; i<N; i++){
	// 	if(vec.size() >= i+1) ans += max(A[i], vec[i]);
	// 	else ans += A[i];
	// }
	// cout << ans << endl;

	// 解2 priority_queueを使う
	priority_queue<LP> pri_qu;
	for(int i=0; i<N; i++) pri_qu.push(LP(A[i], 1));
	for(int i=0; i<M; i++) pri_qu.push(CB[i]);

	ll ans = 0;
	for(int i=0; i<N; i++){
		ll value = pri_qu.top().first;
		ll num = pri_qu.top().second;
		pri_qu.pop();
		ans += value;
		num--;
		if(num > 0) pri_qu.push(LP(value, num));
	}
	cout << ans << endl;


}

