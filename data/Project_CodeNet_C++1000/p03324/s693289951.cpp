	#include<bits/stdc++.h>
	using namespace std;
	using lli = long long;
	#define rep(i,n) for(int i=0;i<n;i++)
	
	int d, n;
	
	int main(void){
		cin >> d >> n;
		if(n == 100){
			n += 1;
		}
		rep(i, d) n*=100;
		cout << n << endl;
		return 0;
	}
