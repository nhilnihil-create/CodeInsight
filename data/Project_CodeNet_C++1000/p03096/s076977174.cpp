#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
const int mod = 1e9+7;

int main(){
	int t,n,maxnum;
	cin >> t; cin >> n;
	vector<int> s;
	s.push_back(n);
	maxnum = n;
	while(--t){
        cin >> n;
		if(n == s.back())continue;
		s.push_back(n);
		if(n > maxnum)maxnum = n;
	}
    int dp[s.size()+1];
	int save[maxnum+1];
	memset(save, 0, sizeof(save));
    dp[0] = 1;
    for(int i = 0; i < s.size(); ++i){
		dp[i+1] = (dp[i] + save[s[i]])%mod;
		save[s[i]] = (save[s[i]]+ dp[i])%mod; 
    }
    cout << dp[s.size()];
	return 0;
} 