#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n,m,c,i; cin >> n >> m >> c;
	int b[m],a[m],k=0,x;
	
	for (i=0 ; i<m ; i++) cin >> b[i];
	
	while (n){
		n--;
		x = 0;
		
		for (i=0 ; i<m ; i++){
			cin >> a[i];
			x += a[i]*b[i];
		}
		
		if (x+c > 0) k++;		
	}
	
	cout << k << endl;
	
	return 0;
}