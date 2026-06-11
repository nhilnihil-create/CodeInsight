//g++ -std=c++14 test.cpp -o test.out
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
using namespace std;

#define LL long long int

int N,M;
int A[10];

string ans = "";

bool is_a_bigger(const string a,const string b){//aの方が大きいかどうかを返す
	if(a.length()!=b.length()) return a.length()>b.length();
	for(int i=0;i<a.length();i++){
		if(a[i]!=b[i]) return a[i]>b[i];
	}
	return false;
}

void solve(){
	int num2match[10];//iを作るのに必要なマッチの数をnum2match[i]とおく
	num2match[1] = 2;
	num2match[2] = 5;
	num2match[3] = 5;
	num2match[4] = 4;
	num2match[5] = 5;
	num2match[6] = 6;
	num2match[7] = 3;
	num2match[8] = 7;
	num2match[9] = 6;
	string dp[10001];//マッチ棒i本で作れる最大値をdp[i]とおく
	for(int i=1;i<=N;i++) dp[i] = "-";
	dp[0] = "";
	for(int i=1;i<=N;i++){
		for(int n=0;n<M;n++){
			if(i-num2match[A[n]]>=0){
				if(dp[i-num2match[A[n]]]!="-"){
					string new_dp = to_string(A[n])+dp[i-num2match[A[n]]];
					if(is_a_bigger(new_dp,dp[i])){
						dp[i] = new_dp;
					}
				}
			}
		}
	}
	ans = dp[N];
}
 
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++)cin >> A[i];
 
	solve();

	cout << ans << endl;
	return 0;
}
