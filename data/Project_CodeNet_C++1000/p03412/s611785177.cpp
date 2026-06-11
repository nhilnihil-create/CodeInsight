#include<bits/stdc++.h>

using namespace std;

#define l(a)std::lower_bound(B,B+n,a-A)

int n,a[2<<18],B[1<<18],s,A,i=1,j,L;

int main(){
	for(;cin>>(n?a[A++]:n););
	for(;i<1<<29;i*=2){
		for(j=0;j<n;j++)B[j]=a[n+j]%(i*2);
		for(std::sort(B,B+n);
		j--;
		s^=(a[j]&i?n-L:L)%2*i)A=a[j]%i,L=l(i*2)-l(i);
		}
	std::cout<<s;
}