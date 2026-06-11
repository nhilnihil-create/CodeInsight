#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct s {
	int t, f, c;
};

int main(void){
	int l; cin >> l;
	int n=0; vector<s> v;
	while (l>=1<<n) n++;
	for(int i=0; i<n-1; i++) {
		v.push_back({i+1, i+2, 0});
		v.push_back({i+1, i+2, 1<<i});
		if (l!=(1<<i) && l & (1<<i)) v.push_back({i+1, n, l - (l&(1<<i))});
		l &= ~(1<<i);
	}
	int m = v.size();
	cout << n << " " << m << endl;
	for(int i=0; i<m; i++) {
		cout << v[i].t << " " << v[i].f << " " << v[i].c << endl;
	}
}