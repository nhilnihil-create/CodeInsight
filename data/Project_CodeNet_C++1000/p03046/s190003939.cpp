#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int m,k;
	scanf("%d%d",&m,&k);
	if(m == 0){
		if(k>0)puts("-1");
		else puts("0 0");
		return 0;
	}
	if(m == 1){
		if(k == 0)puts("0 0 1 1");
		else puts("-1");
		return 0;
	}
	m = 1<<m;
	if(k >= m){
		puts("-1");
		return 0;
	}
	vector<int> ret;
	for(int i = 0 ; i < m ; i ++){
		if(i != k)printf("%d ",i);
	}
	printf("%d ",k);
	for(int i = m-1 ; i >= 0 ; i --){
		if(i != k)printf("%d ",i);
	}
	printf("%d\n",k);
}