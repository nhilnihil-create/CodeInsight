#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int n,i,ans,c;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++){
	cin >> a[i];
	}
	sort(a,a+n);
	ans = a[n-1];
	for(i=0;i<n-1;i++){
		ans = min(abs(2*a[i]-a[n-1]),ans);
		if(ans == abs(2*a[i]-a[n-1])){
			c = i;
		}
	}
	cout << a[n-1] << " "<< a[c] << endl;
	}
	