#include <bits/stdc++.h>
using namespace std;
const int N=2002;
const int B=4000000+1;
int n,a[N],sum=0;
bitset<B> f;
int main(){
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f=f|(f<<a[i]);
		sum+=a[i];
	}
	for(int i=(sum+1)/2;;i++)if(f[i]){
		return !printf("%d\n", i);
	}

}
/*
1 3
0 1 3 4
*/