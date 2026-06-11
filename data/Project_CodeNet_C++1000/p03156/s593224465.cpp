#include <bits/stdc++.h>

const int N = 10005;

using namespace std;

int a[N];

int main() {
	int n, x, y; cin >> n >> x >> y;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int first = 0, sec = 0, thi = 0;
	for(int i = 0;i < n;i++){
		if(a[i] <= x){
			first++;
		}if(a[i] >= x+1 && a[i] <= y){
			sec++;
		}if(a[i] >= y+1){
			thi++;
		}
	}
	cout << min(first,min(sec, thi));
	return 0;
}