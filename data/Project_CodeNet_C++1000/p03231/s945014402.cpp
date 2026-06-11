#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7;
char stra[_] , strb[_]; int N , M;

int main(){
	scanf("%d %d %s %s" , &N , &M , stra + 1 , strb + 1);
	int t = __gcd(N , M);
	for(int i = 0 ; i < t ; ++i) if(stra[N / t * i + 1] != strb[M / t * i + 1]){puts("-1"); return 0;}
	cout << 1ll * N * M / t; return 0;
}