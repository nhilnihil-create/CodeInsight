#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	double total = 0, a;
  	string s;
  	int n;
	cin >>n ;
	rep(i, n){
		cin >> a >> s;
      	total += (s == "BTC" ? a * 380000.0 : a);
	}
	printf("%8.8lf\n", total);	
}
