#include<bits/stdc++.h>
using namespace std;
bitset<4000000+5> q;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		q|=(q<<x);
		q.set(x);
	}
	int S=0;
	for(int i=0;i<=4000000;i++){
		S+=q[i];
	}
	S=ceil(1.*S/2);
	int s=0;
	for(int i=0;i<=4000000;i++){
		s+=q[i];
		if(s>=S){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}