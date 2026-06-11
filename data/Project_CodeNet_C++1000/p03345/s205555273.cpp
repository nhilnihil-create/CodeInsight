#include <bits/stdc++.h>
using namespace std;
long long a , b , c , k , sum;
int main(){
	cin >> a >> b >> c >> k;
	sum = a - b;
	if(k % 2 == 0)cout << sum << endl;
	else cout << -sum << endl;
}