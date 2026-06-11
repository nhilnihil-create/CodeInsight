#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int n,m;
	cin >>n >> m;
	cout << (m%n == 0 ? m+n : m-n) << endl;
}
