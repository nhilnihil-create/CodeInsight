#include <bits/stdc++.h>
using namespace std;
const int maxn = 2002;
bitset<maxn * maxn> f;
int main(){
	int s = 0;
	int n; cin >> n;
	f[0] = 1;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		f = f|(f<<x);
		s += x;
	}
	s += 1;
	s /= 2;
	while(!f[s]) s++;
	cout << s << endl;
	return 0;
}

