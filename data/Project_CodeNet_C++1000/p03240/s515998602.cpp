#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long memo=-1;
	long long x[n],y[n],h[n];
	for(long long i=0;i<n;i++){
		cin >> x[i] >> y[i] >> h[i];
		if(h[i]!=0) memo=i;
	}
	if(n==1){
		cout << x[0] << " " << y[0] << " " << h[0] << endl;
		return 0;
	}
	for(long long i=0;i<=100;i++){
		for(long long j=0;j<=100;j++){
			bool ok=true;
			long long hh=h[memo]+abs(x[memo]-i)+abs(y[memo]-j);
			for(long long k=0;k<n;k++){
				if(h[k]!=max(hh-abs(x[k]-i)-abs(y[k]-j),0LL)){
					ok=false;
				}
			}
			if(ok){
				cout << i << " " << j << " " << hh << endl;
				return 0;
			}
		}
	}
}
