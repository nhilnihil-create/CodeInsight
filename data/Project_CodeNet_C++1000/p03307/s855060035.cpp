#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n&1){
		printf("%d\n",n<<1);
	}
	else{
		printf("%d\n",n);
	}
	return 0;
} 