#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 10;
int a[maxn] , n;

int abs(int x){
	return x > 0 ? x : -x;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1 ; i <= n ; ++ i)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	int c = 1;
	for(int i = 1 ; i < n ; ++ i)
		if(abs(2 * a[i] - a[n]) < abs(2 * a[c] - a[n]))
			c = i;
	cout << a[n] << " " << a[c] << endl;
	return 0;
}