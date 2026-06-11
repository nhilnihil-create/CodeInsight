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


// int chmin(int &a, int b){ return a = min(a, b);}
int chmin(int &a, int b){ return a = min(a, b); }

int main(){
	int N;
	cin >> N;
	
	//解法1 6の倍数をi円  9の倍数をN-i円で分けて考えて
	// iを 6進数で　　　N-iを9進数で考える方法(解説見ました)
	int ans = N;
	for(int i=0; i<=N; i++){
		// cout << " ---------------------- i: " << i << endl;
		int num6 = i;

		int cnt = 0;
		int pow6 = pow(6, 6);// 6^7 = 20万を超える		
		while(num6 > 0){
			int num = num6 / pow6;
			num6 -= num* pow6;
			pow6 /= 6;
			cnt += num;
			// cout << "  pow6: " << pow6 << "  num6: " << num6 << "   num: " << num <<  "   cnt: " << cnt  << "   ans: " << ans  << endl;
		}

		int num9 = N-i;
		int pow9 = pow(9, 5); // 9^6 = 50万を超える
		while(pow9 > 0 ){
			int num = num9 / pow9;
			num9 -= num* pow9;
			pow9 /= 9;
			cnt += num;
			// cout << "  pow9: " << pow9 << "  num9: " << num9 << "   num: " << num <<  "   cnt: " << cnt << "   ans: " << ans  << endl;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;


	//解法2 dp解法
	// vector<int> yen;
	// yen.push_back(1);
	// for(int i=1; i<=5; i++) yen.push_back(pow(9, i));
	// for(int i=1; i<=6; i++) yen.push_back(pow(6, i));
	// sort(yen.rbegin(), yen.rend());
	// 
	// // dp[i][j]: i-1番目のお札まで考慮した時に j円を作ることができる最小手数
	// const int INF = N;
	// vector<vector<int>> dp((int)yen.size()+2, vector<int>(N+1, INF+1));
	// dp[0][0] = 0;

	// for(int i=0; i<=(int)yen.size(); i++){
	// 	for(int j=0; j<=N; j++){
	// 		chmin(dp[i+1][j], dp[i][j]);// //yen[i]を使わない
	// 		if(j+yen[i] <= INF) chmin(dp[i+1][j+yen[i]], dp[i][j] + 1);// yen[i]を1回目使う
	// 		if(j+yen[i] <= INF) chmin(dp[i+1][j+yen[i]],dp[i+1][j] + 1);// yen[i]を2回目以上使う
	// 	}
	// }

	// // print_vec2(dp);
	// cout << dp[(int)yen.size()][N] << endl;

	
	return 0;
}

