#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y,z,k,i,j;
	cin >> x >> y >> z >> k;

	vector<long> a(x),b(y),c(z);
	for(i=0; i<x; i++){
		cin >> a[i];
	}
	for(i=0; i<y; i++){
		cin >> b[i];
	}
	for(i=0; i<z; i++){
		cin >> c[i];
	}
	
	vector<long> t(x*y,0);
	for(i=0; i<x; i++){
		for(j=0; j<y; j++){
			t[i*y+j]=a[i]+b[j];
		}
	}
	
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	
	vector<long> ans(min(k,x*y)*z,0);
	
	for(i=0; i<min(k,x*y); i++){
		for(j=0; j<z; j++){
			ans[i*z+j]=t[i]+c[j];
		}
	}
	
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	for(i=0; i<k; i++){
		cout << ans[i] << endl;
	}
	return 0;
}