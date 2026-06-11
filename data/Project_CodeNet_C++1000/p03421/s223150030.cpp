#include <iostream>
#include <algorithm>

using namespace std;

int res[300000];

int main(){
	long long n, a, b;
	cin >> n >> a >> b;

	if(a+b > n+1 || a*b < n){
		cout << -1 << endl;
		return 0;
	}

	int r = n;
	int past = 0;
	int i=0;
	while(r > 0){
		int len;
		len = min(a, r - b + past + 1);
		for(int m=r-len+1; m<=r; m++)
			res[i++] = m;
		
		past += 1;
		r = r - len;
	}

	cout << res[0];
	for(int i=1; i<n; i++)
		cout << " " << res[i];
	cout << endl;


	return 0;
}
