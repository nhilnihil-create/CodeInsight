#include <iostream>
#include <algorithm>

using namespace std;
long long c[30][200020],d[30][200020];
int main(){
	long long i,j,n,a,b,e,x,ans=0;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a;
		x = 1;
		for(j=1;j<30;j++){
			x *= 2;
			c[j][i] = a%x;
		}
	}
	for(i=0;i<n;i++){
		cin >> b;
		x = 1;
		for(j=1;j<30;j++){
			x *= 2;
			d[j][i] = b%x;
		}
	}
	for(j=1;j<30;j++){
		sort(c[j],c[j]+n);
		sort(d[j],d[j]+n);
	}
	x = 1;
	for(j=1;j<30;j++){
		e = 0;
		for(i=0;i<n;i++){
			e += lower_bound(d[j],d[j]+n,2*x-c[j][i])-lower_bound(d[j],d[j]+n,x-c[j][i])+lower_bound(d[j],d[j]+n,4*x-c[j][i])-lower_bound(d[j],d[j]+n,3*x-c[j][i]);
		}
		ans += x*(e%2);
		x *= 2;
	}
	cout << ans << endl;
}