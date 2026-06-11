#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[3],k;
	cin >> a[1] >> a[2] >> a[3] >> k;
	sort(a+1,a+4);
	cout << pow(2,k)*a[3]+a[1]+a[2]; 
}