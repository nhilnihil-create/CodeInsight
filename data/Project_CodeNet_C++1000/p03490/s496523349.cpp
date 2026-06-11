#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

string s;
llint x, y;
vector<llint> vecx, vecy;
bool dp[8005][16005];
llint Zero = 8002;

bool check(vector<llint> vec, llint x)
{
	if(x < -8000 || x > 8000) return false;
	llint n = vec.size();
	for(int i = 0; i <= n; i++){
		for(int j = -8000; j <= 8000; j++){
			dp[i][Zero+j] = false;
		}
	}
	dp[0][Zero] = true;
	
	for(int i = 0; i < n; i++){
		for(int j = -8000; j <= 8000; j++){
			if(!dp[i][Zero+j]) continue;
			if(j+vec[i] <= 8000) dp[i+1][Zero+j+vec[i]] = true;
			if(j-vec[i] >= -8000) dp[i+1][Zero+j-vec[i]] = true;
		}
	}
	return dp[n][x+Zero];
}

int main(void)
{
	cin >> s >> x >> y;
	s += "T";
	
	bool flag = true; llint cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'F') cnt++;
		else{
			if(flag) vecx.push_back(cnt);
			else vecy.push_back(cnt);
			cnt = 0, flag = !flag;
		}
	}
	x -= vecx.front();
	vecx.erase(vecx.begin());
	
	if(check(vecx, x) && check(vecy, y)) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}