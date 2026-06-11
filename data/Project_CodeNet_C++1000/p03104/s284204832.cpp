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

ll func(ll A){

	// // 解1 
	// ll res = 0;

	// A++; // 周期的に考えてると0からスタートしてしまうので，インクリメント
	// for(int i=0; i<50; i++){
	// 	//Aを2進数の0~50桁目の各桁について
	// 	//1の個数を数える
	// 	ll loop = (ll)1 << (i+1);//00001111000011...という感じで01の周期
	// 	ll cnt = A/loop * loop/2;//周期の半分が1なので Aの中の周期数×周期の半分，半分が1

	// 	//周期のはみ出たところの1を足す
	// 	//(loop個のうちの半分は0なので，Aが0で終わってたらマイナスになるので0とmaxをとる
	// 	cnt += max((ll)0,  A%loop - loop/2);
	// 	// cout << " i: " << i << " cnt: " << cnt << " cnt%2: " << cnt%2 << endl;
	// 	if(cnt % 2 == 1){
	// 		res += (ll)1 << i;
	// 	}

	// }
	// return res;

	//解2
	ll r = A % 4;
	if(r == 0) return (ll)A;
	if(r == 1) return (ll)A^(A-1);
	if(r == 2) return (ll)A^(A-1)^(A-2);
	if(r == 3) return (ll)0;//A^(A-1)^(A-2)^(A-3)=0になる	
	return 0;
}

int main(){
	ll A, B;
	cin >> A >> B;

	// A~BのXOR   =  (0~BのXOR)  XOR  (0~A-1のXOR)
	//なぜなら a^a = 0 である．
	// 例: (4^5^6^7) = (1^2^3^4^5^6^7) ^ (1^2^3)
	ll ans = func(B)^func(A-1);
	// cout << " func(A-1): " << func(A-1) << "  func(B): " << func(B) << endl;
	cout << ans << endl;
}

