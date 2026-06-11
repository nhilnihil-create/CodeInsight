#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
int n, a, ac, m;
bitset<2000005> bt;
int main(){
	bt[0] = true;
	scanf("%d", &n);
	rep(i,n){
		scanf("%d", &a);
		ac += a;
		bt |= bt << a;
	}
	rep(i,ac/2+1) if(bt[i]) m = i;
	printf("%d\n", ac - m);
}