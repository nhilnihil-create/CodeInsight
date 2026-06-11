#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
typedef long long ll;
#define inc(i) (++ (i))
#define dec(i) (-- (i))
#define Rep(i , a , b) for(int i = (a) , i##Limit = (b) ; i <= i##Limit ; inc(i))
#define rep(i , a , b) for(int i = (a) , i##Limit = (b) ; i >= i##Limit ; dec(i))
using namespace std;

const int N = 2000 + 7 , M = 4000000 + 7;
int n , k , Sum , A[N] , B[N * 20] , tot;
bitset <M> Dp;

int main() {
	// scanf("%d%d" , &n , &k);
	scanf("%d" , &n) , k = 0;
	Rep(i , 1 , n) scanf("%d" , A + i) , Sum += A[i];
	if(k == 1) printf("%d\n%d" , Sum * (k + 1) / 2 , Sum * (k + 1) / 2);
	else {
		// printf("%d\n" , Sum * (k + 1) / 2);
		// Rep(i , 1 , n) Rep(j , 1 , k) B[inc(tot)] = A[i] * j;
		Dp[0] = 1;
		Rep(i , 1 , n) Dp |= Dp << A[i];
		int Now = (Sum + 1) * (k + 1) / 2;
		// rep(i , Now , 0) if(Dp[i]) return printf("%d" , i) , 0;
		Rep(i , Now , Sum * (k + 1)) if(Dp[i]) return printf("%d" , i) , 0;
	}
	return 0;
}