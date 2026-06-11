#include <bits/stdc++.h>
using namespace std;

#define MAX_N 2003

bitset <MAX_N*MAX_N> bs;

int main()
{
	int n ,sum = 0;
	scanf("%d",&n);
	bs[0] = 1;
	for(int a,i=0; i<n; i++){
		scanf("%d",&a);
		bs |= (bs << a);
		sum += a;
	}
	
	for(int i=(sum+1)/2; i<bs.size(); i++)
		if(bs[i]){
			printf("%d\n",i);
			return 0;
		}
}