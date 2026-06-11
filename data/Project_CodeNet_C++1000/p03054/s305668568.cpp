#include<bits/stdc++.h>
using namespace std;

#define PII pair < int , int >
const int _ = 4e5 + 7;
char str[2][_]; int N , H , W , X , Y , dp[_][2];

int main(){
	scanf("%d %d %d %d %d %s %s" , &H , &W , &N , &X , &Y , str[0] , str[1]);
	vector < PII > q;
	for(int i = 0 ; i < N ; ++i){
		if(str[0][i] == 'L' || str[0][i] == 'R') q.push_back(PII(0 , str[0][i] == 'R'));
		if(str[1][i] == 'L' || str[1][i] == 'R') q.push_back(PII(1 , str[1][i] == 'R'));
	}
	for(int i = q.size() - 1 ; i >= 0 ; --i){
		dp[i][0] = dp[i + 1][0]; dp[i][1] = dp[i + 1][1];
		if(q[i].first == 0) ++dp[i][q[i].second];
		else dp[i][q[i].second ^ 1] = max(dp[i][q[i].second ^ 1] - 1 , 0);
	}
	for(int i = 0 ; i < q.size() ; ++i){
		if(q[i].first == 0){
			if(q[i].second == 0 && Y - dp[i][0] <= 0 || q[i].second == 1 && Y + dp[i][1] > W)
				Y += q[i].second == 0 ? -1 : 1;
		}
		else 
			if(q[i].second == 0 && Y + dp[i + 1][1] > W || q[i].second == 1 && Y - dp[i + 1][0] <= 0)
				Y += q[i].second == 0 ? -1 : 1;
		if(Y <= 0 || Y > W) return puts("NO") , 0;
	}
	memset(dp , 0 , sizeof(dp)); q.clear();
	for(int i = 0 ; i < N ; ++i){
		if(str[0][i] == 'U' || str[0][i] == 'D') q.push_back(PII(0 , str[0][i] == 'D'));
		if(str[1][i] == 'D' || str[1][i] == 'U') q.push_back(PII(1 , str[1][i] == 'D'));
	}
	for(int i = q.size() - 1 ; i >= 0 ; --i){
		dp[i][0] = dp[i + 1][0]; dp[i][1] = dp[i + 1][1];
		if(q[i].first == 0) ++dp[i][q[i].second];
		else dp[i][q[i].second ^ 1] = max(dp[i][q[i].second ^ 1] - 1 , 0);
	}
	for(int i = 0 ; i < q.size() ; ++i){
		if(q[i].first == 0){
			if(q[i].second == 0 && X - dp[i][0] <= 0 || q[i].second == 1 && X + dp[i][1] > H)
				X += q[i].second == 0 ? -1 : 1;
		}
		else 
			if(q[i].second == 0 && X + dp[i + 1][1] > H || q[i].second == 1 && X - dp[i + 1][0] <= 0)
				X += q[i].second == 0 ? -1 : 1;
		if(X <= 0 || X > H) return puts("NO") , 0;
	}
	puts("YES"); return 0;
}