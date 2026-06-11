#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	cout << max(c/a, 0)*b << endl;
}
