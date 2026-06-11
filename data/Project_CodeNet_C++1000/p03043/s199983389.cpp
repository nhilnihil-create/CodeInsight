#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n,k;
	// nyuryoku
	cin >> n >> k;
	// keisan
	double ans = 0,tmp;
	for(int i=1;i <= n;i++){
		tmp = (double)1/n;
		int now = i;
		while(now < k){
			now *= 2;
			tmp = tmp/2;
		}
		ans += tmp;
	}
	// syutsuryoku
	printf("%.12lf\n",ans);
}