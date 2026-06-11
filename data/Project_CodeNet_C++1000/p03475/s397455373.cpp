#include <bits/stdc++.h>
using namespace std;
const int maxn = 800;
int c[maxn], s[maxn], f[maxn];
int main() {
	int n;
	cin >> n;
	for(int i= 0; i < n - 1; ++i) cin >> c[i] >> s[i] >> f[i];
	for(int i = 0; i < n - 1; ++i){
		long long now = s[i] + c[i];
		for(int j = i + 1; j < n - 1; ++j){
			long long need = max( (long long)ceil( (now - s[j])*1.0/f[j] ) , 0LL ); //s[i] + x*f[i] >= now
			now = s[j] + need*f[j] + c[j];
		}
		cout << now << endl;
	}
	cout << 0;
	return 0;
}