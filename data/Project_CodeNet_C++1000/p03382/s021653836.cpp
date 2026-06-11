#include <iostream>
#include <algorithm>
using namespace std;
int a[1000006];
int aabs(int x){
	return x >= 0 ? x : -x;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	int x = (a[n] + 1) / 2;
	int ans = n;
	for (int i = 1; i < n; ++ i)
		if (ans == n || aabs(x - a[i]) < aabs(x - a[ans]))
			ans = i;
	cout << a[n] << " " << a[ans] << endl;
}
