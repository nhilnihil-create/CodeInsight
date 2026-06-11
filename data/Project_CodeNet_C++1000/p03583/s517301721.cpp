#include <bits/stdc++.h>
using namespace std;
int main(){
long long n,k,l;
cin >> n;
if (n%2==0){
	cout << n << ' ' << n << ' ' << n/2;
	return 0;
}
if (n%3==0){
	cout << n << ' ' << n/3*2 << ' ' << n/3*2;
	return 0;
}
if ((n-3)%4==0){
	cout << (n+1)/4 <<' ' << (n+1)/4*(n+1)<<' ' <<(n+1)/4*(n+1)*n;
	return 0;
}
if ((n-1)%4==0){
for (long long i=1;i<=3500;i++){
	for (long long j=1;j<=3500;j++){
		  k=n*i*j,l=4*i*j-n*i-n*j;//数学 
        if (l>0&&k%l==0){
        	cout << i << ' ' << j << ' ' << k/l << endl;
        	return 0;
        }
	}
} 
}
}