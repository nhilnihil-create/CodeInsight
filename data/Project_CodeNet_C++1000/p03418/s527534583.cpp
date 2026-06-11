#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, int num=0){
  if(num == 0) num = (int)v.size();
  if(is_reverse) for(int i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<" ";}
  else for(int i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<" ";}
  cout << endl;
}

template <typename T>
void print_pairvec(const vector<T> &v, int num=0){
  if(num == 0) num = (int)v.size();
  cout << endl;
  for(int i=0; i<num; i++){ cout << v[i].first << " " << v[i].second << endl;}
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

	ll ans = 0;
	// O(N^2)なのでダメでした
	// for(int a = K; a<=N; a++){
	// 	for(int b = K+1; b<=N; b++){
	// 		if(a == 0) break;//K=0のときにa=0として計算されるが,aは正の整数なので除外
	// 		if(a < b) {
	// 			ans += N - b + 1;
	// 			break;
	// 		}
	// 		if(a%b >= K) ans++;
	// 	}
	// }


	if(K==0){
		cout << (ll)N * N << endl;
		return 0;
	}
	for(int b=K+1; b<=N; b++){		
		int tmp1 = (N-K+1) / b;//　何周期　あまりが　ぐるぐる回るか
		int tmp2 = b - K ;// 1周期(0~ b-1 の中)にK以上のものが何個あるか 
		ans += tmp1 * tmp2;   // 

		// for(int a = b+1; a<=N; a++){}
		int tmp3 = (N-K+1) % b;// 周期の最後にaが Nに達するまで何回インクリメントできるか
		ans += min(tmp3, tmp2);
	}


	cout << ans << endl;

	return 0;
}

