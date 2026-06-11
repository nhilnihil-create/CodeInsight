#include <bits/stdc++.h>

using namespace std;

vector<int> F, T; // F = sidewards, T = upwards
string s;
int x, y;
set<int> dp[2];
int main(){
	//freopen("ftrobot.in", "r" ,stdin);
	cin >> s >> x >> y; 
	s += 'T';
	int cur = 0;
	bool dir = 0;
	bool firstturn = 1;
	for(auto i : s){
		if(i == 'T'){
			if(firstturn){
				dp[0].insert(cur); // forced to move this way
				firstturn = false;
			}
			else if(cur == 0){}
			else if(dir==0) F.push_back(cur);
			else T.push_back(cur);
			cur = 0;
			dir = 1-dir;
		}else cur++;
	}
//	printf("F: "); for(auto i : F) printf("%d ", i); printf("\n");
//	printf("T: "); for(auto i : T) printf("%d ", i); printf("\n");
	for(int i = 0; i<F.size(); i++){
		int ii = i%2;
		dp[1-ii].clear();
		for(auto j : dp[ii]){
			dp[1-ii].insert(j-F[i]);
			dp[1-ii].insert(j+F[i]);
		}
	}
	bool ans = true;
	if(dp[F.size()%2].find(x) == dp[F.size()%2].end()) ans = false;
	dp[0].clear();
	dp[0].insert(0);
	for(int i = 0; i<T.size(); i++){
		int ii = i%2;
		dp[1-ii].clear();
		for(auto j : dp[ii]){
			dp[1-ii].insert(j-T[i]);
			dp[1-ii].insert(j+T[i]);
		}
	}
	if(dp[T.size()%2].find(y) == dp[T.size()%2].end()) ans = false;
	cout << (ans ? "Yes" : "No");
}
