#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 2003;
int X[_] , Y[_] , len[_] , N , M , all , sum;

void work(int p , int q){
	int x = p + q , y = p - q , nposx = (all + x) / 2 , nposy = (all + y) / 2;
	for(int i = 0 ; i < M ; ++i){
		int flgx = (nposx >> i & 1) || nposx == all , flgy = (nposy >> i & 1) || nposy == all;
		switch(flgx * 2 + flgy){
		case 3: putchar('R'); break;
		case 2: putchar('U'); break;
		case 1: putchar('D'); break;
		case 0: putchar('L'); break;
		}
	}
}

signed main(){
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		cin >> X[i] >> Y[i]; all = max(all , max(abs(X[i] + Y[i]) , abs(X[i] - Y[i])));
		if(i != 1 && ((X[i] + Y[i] + X[i - 1] + Y[i - 1]) & 1)){puts("-1"); return 0;}
	}
	int sum = 0; for(int i = 0 ; sum <= all ; ++i) sum += (len[++M] = 1 << i);
	if((all - sum) & 1){len[++M] = 1; ++sum;}
	all = sum; printf("%lld\n" , M);
	for(int i = 1 ; i <= M ; ++i) printf("%lld " , len[i]);
	putchar('\n'); for(int i = 1 ; i <= N ; ++i , putchar('\n')) work(X[i] , Y[i]);
	return 0;
}