#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, d[55], ans;
int main(){
	scanf("%d", &n);
	rep(i,n) scanf("%d", d+i);
	sort(d,d+n);
	for(int i = 12; i >= 0; i--){
		int l[2] = {0,0}, k = 0;
		bool ok = true;
		rep(j,n){
			if(l[k]+i <= d[j] && l[!k]+i+d[j] <= 24) l[k] = d[j];
			else if(l[k^=1]+i <= d[j] && l[!k]+i+d[j] <= 24) l[k] = d[j];
			else{
				ok = false;
				break;
			}
			
		}
		if(ok){
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
}