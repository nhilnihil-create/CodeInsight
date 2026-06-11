#include<bits/stdc++.h>
using namespace std;

int n,x,sum;
bitset<4000005>s;

int main(){
	s[0]=1;scanf("%d",&n);while(n--){
		scanf("%d",&x);sum+=x;
		s|=s<<x;
	}
	for(register int i=(sum+1)/2;i<=sum;i++)
		if(s[i]){printf("%d\n",i);return 0;}
}