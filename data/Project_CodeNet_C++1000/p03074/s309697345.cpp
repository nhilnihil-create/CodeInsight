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
	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;

	vector<int> A;
	char group = S[0];//'0'のグループか '1'のグループかを格納
	int cnt = 0;
	for(int i=0; i<N; i++){
		if(S[i] == group) cnt++;
		else{
			A.push_back(cnt);
			group = S[i];
			cnt = 1;
		}
	}
	A.push_back(cnt);

	// if(A.size() == 1){ 
		// ここ入れないと 入力が 1 1 0　のとき，2K回ループするところで範囲外参照起こす
		// もう A.size()を intにキャストすることで解決したので　ここはコメントアウト
	// 	cout << N << endl;
	// 	return 0;
	// }
	vector<int> wa;
	wa.push_back(0);
	for(int i=0; i<A.size(); i++) wa.push_back(wa.back()+A[i]);
	// cout << " A: "; print_vec(A);

	int ans = 0;
	if(S[0] == '0'){//左端が0のグループの場合
		int tmp = 0;
		for(int i=0; i<2*K; i++){
			if(i<A.size()) tmp += A[i];
		}
		ans = max(ans, tmp);	
	}
	if(S.back() == '0'){//右端が0のグループの場合
		int tmp = 0;
		for(int i=0; i<2*K; i++){
			if(int(A.size())-1 - i >= 0) tmp += A[A.size()-1 - i];// A.size()をintにキャストしないと， A.size()-1が範囲外参照的な感じで壊れた値になる
			// cout << " i : " << i << "     A.size(): " << A.size() <<  "   index: " << (int)A.size() - 1 - i <<  "    tmp: " << tmp << endl;
		}
		ans = max(ans, tmp);
	}
	// cout << "1 A.size() = " << A.size() << "    wa.size() = " << wa.size() << endl;
	if(S[0] == '0'){
		reverse(wa.begin(), wa.end());
		wa.pop_back();
		reverse(wa.begin(), wa.end());
	}
	// cout << "2 A.size() = " << A.size() << "    wa.size() = " << wa.size() << endl;
	if(S.back() == '0') wa.pop_back();
	// cout << "3 A.size() = " << A.size() << "    wa.size() = " << wa.size()<< endl;

	int range = 2*K + 1;
	for(int left = 0; left<wa.size(); left +=2){//0のグループから選ぶ意味はないのでleft+=2
		int right = left + range;
		if(right > wa.size()-1) right = wa.size() - 1;
		if(right < left) continue;
		ans = max(ans, wa[right]-wa[left]);
	}

	cout << ans << endl;
	
	


}

