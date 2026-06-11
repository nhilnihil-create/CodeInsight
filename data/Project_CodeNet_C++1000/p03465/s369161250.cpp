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
int n , Sum , A[N];
bitset <M> Dp;
 
int main() {
	scanf("%d" , &n);
	Rep(i , 1 , n) scanf("%d" , A + i) , Sum += A[i];
	Dp[0] = 1;
	Rep(i , 1 , n) Dp |= Dp << A[i];
	int Now = (Sum + 1) / 2;
	Rep(i , Now , Sum) if(Dp[i]) return printf("%d" , i) , 0;
	return 0;
}