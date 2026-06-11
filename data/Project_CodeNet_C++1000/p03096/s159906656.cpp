#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>

using namespace std;
const int mod = 1e9+7;

int main(){
	int t,n,maxnum = 0;
	cin >> t; cin >> n;
	vector<int> s;
	s.push_back(n);
	while(--t){
        cin >> n;
		if(n == s.back())continue;
		s.push_back(n);
	}
    vector<int> dp(s.size()+1);
    unordered_map<int,int> save;
    dp[0] = 1;
    for(int i = 0; i < s.size(); ++i){
		if(save.count(s[i]) == 0){
			save[s[i]] = dp[i];
			dp[i+1] = dp[i];
		}
		else{
			dp[i+1] = (dp[i] + save[s[i]])%mod;
			save[s[i]] = (save[s[i]]+ dp[i])%mod; 
		}
    }
    cout << dp[s.size()];
	return 0;
} 