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

int main(){

	int n;
	cin >> n;
	map<int, int> even, odd;
	for(int i=0; i<n; i++){	
		int v;
		cin >> v;
		if(i%2 == 0) even[v]++;
		else 	odd[v]++;
	}

	typedef pair<int, int> P;
	vector<P> even2, odd2;
	for(P x : even){
		even2.emplace_back(x.second, x.first);
	}
	for(P x : odd){
		odd2.emplace_back(x.second, x.first);
	}

	sort(even2.rbegin(), even2.rend());
	sort(odd2.rbegin(), odd2.rend());
	int even_cnt = even2[0].first;
	int odd_cnt = odd2[0].first;
	if(even2[0].second != odd2[0].second){//一番多い数字の値がそれぞれ違うなら
		int ans = n - even_cnt - odd_cnt;
		cout << ans << endl;
		return 0;
	}
	if(even2.size() == 1 && odd2.size() == 1){
		cout << n/2 << endl;
		return 0;
	}

	if(even2.size() == 1){
		int ans = n - even_cnt - odd2[1].first;
		cout << ans << endl;
		return 0;
	}
	if(odd2.size() == 1){
		int ans = n - odd_cnt - even2[1].first;
		cout << ans << endl;
		return 0;
	}


	int even_cnt2 = even2[1].first;
	int odd_cnt2 = odd2[1].first;
	int ans;
	if(even_cnt + odd_cnt2 > even_cnt2 + odd_cnt) ans = n - even_cnt - odd_cnt2;
	else ans = n - even_cnt2 - odd_cnt;

	cout << ans << endl;

}

