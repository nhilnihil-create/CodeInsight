#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, ans;
int main(){
	scanf("%d", &n);
	for(; n; n/=10) if(n%10 == 2) ans++;
	printf("%d\n", ans);
}