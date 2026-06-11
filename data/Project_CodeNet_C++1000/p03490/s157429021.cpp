#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
int x, y;
vector<int> vecx, vecy;

bool dp[4005][16005];

bool calcDP(vector<int> &vec, int dst)
{
	const int zero = 8002;
	for(int i = 0; i <= vec.size(); i++){
		for(int j = 0; j < 16005; j++){
			dp[i][j] = false;
		}
	}
	dp[0][zero] = true;
	
	for(int i = 0; i < vec.size(); i++){
		for(int j = 0; j < 16005; j++){
			if(!dp[i][j]) continue;
			if(j - vec[i] >= 0) dp[i+1][j - vec[i]] = true;
			if(j + vec[i] < 16005) dp[i+1][j + vec[i]] = true;
		}
	}
	
	if(zero + dst >= 16005 || zero + dst < 0) return false;
	return dp[vec.size()][zero + dst];
}

int main(void)
{
	cin >> s;
	cin >> x >> y;
	s += "T";
	
	bool flag = false;
	int cnt = 0, dir = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'T'){
			if(!flag){
				x -= cnt;
				flag = true;
			}
			else{
				if(!dir) vecx.push_back(cnt);
				else vecy.push_back(cnt);
			}
			cnt = 0, dir = !dir;
		}
		else cnt++;
	}
	
	if(calcDP(vecx, x) && calcDP(vecy, y)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}