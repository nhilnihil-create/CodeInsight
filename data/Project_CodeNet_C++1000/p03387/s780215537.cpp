#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	int minimum = 100;
	int maxim = max(a,max(b,c));
	int maxim1 = maxim + 1;
	int ans = 0;
	if(maxim%2 == (a+b+c)%2){
		ans = (3*maxim - (a+b+c))/2;
	}
	if(maxim1%2 == (a+b+c)%2){
		ans = (3*maxim1 - (a+b+c))/2;
	}
	cout << ans << endl;
 }