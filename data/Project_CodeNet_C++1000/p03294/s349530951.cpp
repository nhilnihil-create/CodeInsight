#include<bits/stdc++.h>
using namespace std;
int a[3010];
int b[3010];
int n;
int max = n;
int sum = 0;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	cout << sum - n;
}