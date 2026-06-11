#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(ALL(a));
	int m = a[n-1];
	int l = a[0];
	for(int i = 1; i < n - 1; ++i) {
		if(abs((m + 1) / 2 - a[i]) < abs((m + 1) / 2 - l)) {
			l = a[i];
		}
	}
	cout << m << " " << l << endl;
	return 0;
}
