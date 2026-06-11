#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;

template <class T>
string to_binary(T a){
	if(a == 0){
		return "0";
	}
	string res = "";
	while(a > 0){
		res += '0'+(a & 1);
		a >>= 1;
	}
	return res;
}

int main(){
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i = 0;i < n;i++)cin >> a[i];

	map<int,int> mp;
	for(int i = 0;i < n;i++){
		string s = to_binary(a[i]);
		for(int j = 0;j < s.size();j++){
			if(s[j] == '1')mp[j]++;
		}
	}

	string s = to_binary(k);
	reverse(s.begin(),s.end());
	int m = s.size();
	ll st = 0;
	for(int i = 42;i >= m;i--){
		st += (1LL << i) * mp[i];
	}

	vector<vector<ll>> dp(m+1,vector<ll>(2,0));
	//dp[i][0]:=i桁まで決めて等しい. dp[i][1]:=i桁まで決めて未満.
	dp[0][0] = st;

	for(int i = 0;i < m;i++){
		//最初の桁だけ注意.
		if(i == 0){
			if(s[0] == '0'){
				dp[1][0] = dp[0][0] + (1LL << (m-1)) * mp[m-1];
			}
			else{
				//s[0]=='1'
				dp[1][0] = dp[0][0] + (1LL << (m-1)) * (n - mp[m-1]);
				dp[1][1] = dp[0][0] + (1LL << (m-1)) * mp[m-1];
			}
			continue;
		}
		if(s[i] == '0'){
			//等しい->等しい,未満->未満にしか遷移しない.
			dp[i+1][0] = dp[i][0] + (1LL << (m-1-i)) * mp[m-1-i];
			dp[i+1][1] = dp[i][1] + (1LL << (m-1-i)) * max(n-mp[m-1-i],mp[m-1-i]);
		}
		else{//kk[i]=='1'
			//等しい->等しい,等しい->未満,未満->未満に遷移.
			dp[i+1][0] = dp[i][0] + (1LL << (m-1-i)) * (n-mp[m-1-i]);
			dp[i+1][1] = dp[i][0] + (1LL << (m-1-i)) * mp[m-1-i];
			dp[i+1][1] = max(dp[i+1][1],dp[i][1]+(1LL << (m-1-i)) * max(n-mp[m-1-i],mp[m-1-i]));
		}
	}

	cout << max(dp[m][0],dp[m][1]) << endl;
}
