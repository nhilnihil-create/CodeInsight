#include "bits/stdc++.h"
using namespace std;
string dp[11000];
const string MINUSINF = "-";

string compare(string str1 ,string str2) {
	if (MINUSINF == str1) {
		return str2;
	}
	if (str1.size() <str2.size()) {
		return str2;
	}
	if (str1.size() > str2.size()) {
		return str1;
	}
	if (str1 < str2) {
		return str2;
	}
	else {
		return str1;
	}
}

int main() {
	int N, M;
	cin >> N >> M; 
	vector<int>A(M);
	map<int, int>mp;
	mp[1] = 2;
	mp[2] = 5;
	mp[3] = 5;
	mp[4] = 4;
	mp[5] = 5;	
	mp[6] = 6;
	mp[7] = 3;
	mp[8] = 7;
	mp[9] = 6; 
	for (int m = 0;m<M;++m) {
		cin >> A[m];
	}
	for (int i = 0; i < 11000; ++i) { 
		dp[i] = MINUSINF; 
	}
	dp[0] = "";
	for (int i = 0;i<N;++i) {
		if (dp[i] == MINUSINF) continue;
		for (int n = 0;n<A.size();++n) {
			//dp[i + mp[A[n]]] = compare(dp[i + mp[A[n]]],"tset"); 
			string strcopy = dp[i];
			strcopy += ('0' + A[n]);
			dp[i + mp[A[n]]] = compare(dp[i + mp[A[n]]], strcopy);
		}
	}
	cout << dp[N]<<endl;
	return 0;
}