#include <bits/stdc++.h>
using namespace std;

bool dp[8001][40000];
int solve(vector<int> a, int x){
	fill((bool*)dp, (bool*)(dp+8001) , 0);
	dp[0][20000] = 1;
	int n = a.size();
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 40000;j++){
			if(j+a[i] < 40000)dp[i+1][j+a[i]] = max(dp[i+1][j+a[i]], dp[i][j]);
			if(j-a[i] >= 0)dp[i+1][j-a[i]] = max(dp[i+1][j-a[i]], dp[i][j]);
		}
	}
	if(dp[n][20000+x] == true)return 1;
	return 0;
}

int main(){
	vector<int> a, b;
	string str;
	int f = 0, sum = 0, from, x, y;
	cin >> str >> x >> y;
	str.push_back('T');
	
	for(from = 0;from < str.size();from++){
		if(str[from] == 'T')break;x--;
	}
	for(int i = from;i < str.size();i++){
		if(str[i] == 'T' && sum){
			if(f == 0)a.push_back(sum);
			else b.push_back(sum);
			sum = 0;
		}
		if(str[i] == 'F')sum++;
		if(str[i] == 'T')f = !f;
	}
	
	int t1 = solve(a, x);
	int t2 = solve(b, y);
	if(t1 && t2)printf("Yes\n");
	else printf("No\n");
	return 0;
}