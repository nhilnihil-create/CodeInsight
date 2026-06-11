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
	ll N;
	cin >> N;
	string s = to_string(N);
	ll num_digit = s.size();
	// cout << " s:  " << s << "    num_digit:  " << num_digit << endl;
	const int NUM = 11;
	ll dp[NUM][NUM][NUM][NUM][2];
	// dp[i][j][k][l][m]: 
	//上から(i-1)桁目まで数字を決定した時，
	// m=0: 今のところNと同じ値,  m=1:すでにNより小さいと確定
	// 3がj個,  5がk個, 7がl個　のみからなる整数の個数 (3,5,7以外の数字は使ってない整数だけ数える)

	dp[0][0][0][0][0] = 1;// まだ1桁も決定してない段階では 3,5,7以外の数字を使ってない
	for(int i=0; i<num_digit; i++){
		for(int j=0; j<num_digit; j++){
			for(int k=0; k<num_digit; k++){
				for(int l=0; l<num_digit; l++){
					if(j==0 && k==0 && l==0 ) dp[i+1][j][k][l][1] += dp[i][j][k][l][1];//上からi+1桁目を0にする 　これいれないと例えばN=3357が1になる(0357とかが数えられない)
					dp[i+1][j+1][k][l][1] += dp[i][j][k][l][1];//上からi+1桁目を3にする

					dp[i+1][j][k+1][l][1] += dp[i][j][k][l][1];//上からi+1桁目を5にする

					dp[i+1][j][k][l+1][1] += dp[i][j][k][l][1];//上からi+1桁目を7にする

					int nd = s[i]-'0';
					if(j==0 && k==0 && l==0 ) dp[i+1][j][k][l][1] += dp[i][j][k][l][0];//上からi+1桁目を0にする  これいれないと例えばN=3357が1になる(0357とかが数えられない)
					if(nd > 3)  dp[i+1][j+1][k][l][1] += dp[i][j][k][l][0];
					if(nd == 3) dp[i+1][j+1][k][l][0] += dp[i][j][k][l][0];
					if(nd > 5)  dp[i+1][j][k+1][l][1] += dp[i][j][k][l][0];
					if(nd == 5) dp[i+1][j][k+1][l][0] += dp[i][j][k][l][0];
					if(nd > 7)  dp[i+1][j][k][l+1][1] += dp[i][j][k][l][0];
					if(nd == 7) dp[i+1][j][k][l+1][0] += dp[i][j][k][l][0];
					// cout << "  i:  " << i <<  " (3, 5, 7) = (" << j << ", " << k << ", " << l << "):    nd: " << nd << endl;
				}
			}
		}
	}

	ll ans = 0;
	for(int j=1; j<num_digit; j++){
		for(int k=1; k<num_digit; k++){
			for(int l=1; l<num_digit; l++){
				// int l = num_digit - j - k;//これだと 3600とかで 0357といった数を数えられない
				// if(l <= 0) continue;
				ans += dp[num_digit][j][k][l][0];
				ans += dp[num_digit][j][k][l][1];
				// cout << " (3, 5, 7) = (" << j << ", " << k << ", " << l << "):   dp[num_digit][j][k][l][0]: " << dp[num_digit][j][k][l][0] << "  dp[num_digit][j][k][l][1] " <<  dp[num_digit][j][k][l][1] << endl;
			}
		}
	}
	

	// cout << "  dp[2][1][0][1][0]: " <<  dp[2][1][0][1][0]  << "  dp[2][1][1][1][0]: " <<  dp[2][1][1][1][0] << endl;
	cout << ans << endl;
}

