#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	int d = 1;
	int r = 1;
	rep(i, n){
		int a;
		cin >> a;
		if(a%2 == 0){
			r*=2;
		}
		d*=3;
	}
	cout << d-r << endl;
	return 0;
}
