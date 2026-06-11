#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
int n, a[6] = {2,4,3,9,8,10};
int main(){
	scanf("%d", &n);
	if(n == 3) printf("2 5 63\n");
	else{
		int k = n/8, t = 0;
		rep(i,k){
			printf("%d %d %d %d %d %d %d %d", t+2,t+3,t+4,t+6,t+8,t+9,t+10,t+12);
			printf("%s", (i+1)*8 == n ? "\n" : " ");
			t += 12;
		}
		rep(i,n%8/2*2) printf("%d%s", t+a[i], n%8-1==i ? "\n" : " ");
		if(n%2) printf("%d\n", t+6);
	}
}