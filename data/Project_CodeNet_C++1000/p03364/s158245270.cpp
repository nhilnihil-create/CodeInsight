#include<bits/stdc++.h>
using namespace std;

char str[603][603]; int N , len[603][603][2];

int qry(int x1 , int y1 , int tp){
	if(len[x1][y1][tp] != -1) return len[x1][y1][tp];
	int &l = len[x1][y1][tp] = !tp;
	int p = x1 , q = y1 , r = x1 - tp , s = y1 + tp;
	while(str[p + l][q - l] && str[r - l][s + l] && str[p + l][q - l] == str[r - l][s + l])
		++l;
	return l;
}

int main(){
	scanf("%d" , &N); memset(len , -1 , sizeof(len));
	for(int i = 1 ; i <= N ; ++i) scanf("%s" , str[i] + 1);
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j)
			str[i + N][j] = str[i][j + N] = str[i + N][j + N] = str[i][j];
	int ans = 0;
	for(int i = 1 ; i <= N ; ++i)
		for(int j = 1 ; j <= N ; ++j){
			bool flg = 1;
			for(int k = 0 ; k < N ; ++k) flg &= qry(i + k , j + k , 0) >= min(k + 1 , N - k);
			for(int k = 1 ; k < N ; ++k) flg &= qry(i + k , j + k - 1 , 1) >= min(k , N - k);
			ans += flg;
		}
	cout << ans; return 0;
}