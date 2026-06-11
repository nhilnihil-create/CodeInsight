#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

bitset<maxn * maxn> bs;

int n, x, sum;

int main(){
	scanf("%d", &n);
	bs[0] = 1;
	while(n--){
		scanf("%d", &x);
		bs |= bs << x;
		sum += x;
	}
	for(int i = (sum + 1) / 2;;i++) if(bs[i]) return printf("%d", i), 0;
}