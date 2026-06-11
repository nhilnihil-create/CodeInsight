#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[3];
  	cin >> a[0] >> a[1] >> a[2];
  	sort(&a[0],&a[2]+1);
  	cout << a[2]*10+a[1]+a[0];
  	return 0;
}
