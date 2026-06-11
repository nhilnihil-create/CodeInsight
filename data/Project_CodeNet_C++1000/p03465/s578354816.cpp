#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10;
bitset<2*N*N>jl;
int n,a[N];
int main()
{
	scanf("%d",&n);int sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	jl[0]=1;
	for(int i=1;i<=n;i++){
		jl|=(jl<<(a[i]));sum+=a[i];
	}
	for(int i=(sum+1)/2;;i++){
		if(jl[i]){
			cout<<i<<endl;return 0;
		}
	}
}