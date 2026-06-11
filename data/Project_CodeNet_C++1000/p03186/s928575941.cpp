#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	long a,b,c;
	cin >> a >> b >> c;
	cout << (a+b >= c-1  ? b + c : a + 2*b + 1) << endl;
}