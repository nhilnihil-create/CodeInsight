#include <bits/stdc++.h>
using namespace std;

signed main(){
	int y, m, d;
	scanf("%4d/%2d/%2d", &y, &m, &d);
	if(m < 4 || (m == 4 && d <= 30)){
		printf("Heisei\n");
	}
	else{
		printf("TBD\n");
	}
	return 0;
}