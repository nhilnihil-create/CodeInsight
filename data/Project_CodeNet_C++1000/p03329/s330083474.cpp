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
	
	vector<int> yen;
	yen.push_back(1);
	for(int i=1; i<=5; i++) yen.push_back(pow(9, i));
	for(int i=1; i<=6; i++) yen.push_back(pow(6, i));
	sort(yen.rbegin(), yen.rend());

	// dp[i][j]: i-1番目のお札まで考慮した時に j円を作ることができる最小手数
	const int INF = N;
	vector<vector<int>> dp((int)yen.size()+2, vector<int>(N+1, INF+1));
	dp[0][0] = 0;

	for(int i=0; i<=(int)yen.size(); i++){
		for(int j=0; j<=N; j++){
			chmin(dp[i+1][j], dp[i][j]);// //yen[i]を使わない
			if(j+yen[i] <= INF) chmin(dp[i+1][j+yen[i]], dp[i][j] + 1);// yen[i]を1回目使う
			if(j+yen[i] <= INF) chmin(dp[i+1][j+yen[i]],dp[i+1][j] + 1);// yen[i]を2回目以上使う
		}
	}

	// print_vec2(dp);
	cout << dp[(int)yen.size()][N] << endl;



	// for(int i=0; i< (int)yen.size(); i++){
	// 	int sum = 0;
	// 	int cnt = 0;
	// 	for(int j=yen[i]; j<INF; j+= yen[i]){
	// 		if(sum > N) break;
	// 		sum += yen[i];
	// 		cnt++;
	// 	}
	// }

	// for(int i=yen[0]; i<INF; i += yen[0]){
	// 	for(int j=yen[1]; j<INF; j += yen[1]){

	// 	}

	// }


	// using P = pair<int, int>;
	// vector<P> aaa;
	// for(int i=0; i<(int)yen.size(); i++){
	// 	int num = N / yen[i];
	// 	N -= num*yen[i];
	// 	ans += num;
	// 	aaa.push_back(P(yen[i], num));
	// }
	// print_pairvec(aaa);

	// cout << ans << endl;
	return 0;
}

