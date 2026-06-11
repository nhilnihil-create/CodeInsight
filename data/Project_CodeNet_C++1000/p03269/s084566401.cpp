#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)
 
using namespace std;
 
typedef long long ll;
struct edge{
	int u, v, cost;
};
 
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	int l;
	cin >> l;
	l--;
 
	int r = 0;
	while((1 << (r + 1)) - 1 <= l) r++;
 
	vector<edge> v;
	int m = 0;
	rep(i, r){
		v.push_back({i+1, i+2, 1 << i});
		v.push_back({i+1, i+2, 0});
		m += 2;
	}
 
	int val = (1 << r) - 1;
	for(int i = r-1; i >= 0; i--){
		if(l >= val + (1 << i)){
			v.push_back({i+1, r+1, val + 1});
			m++;
			val += (1 << i);
		}
	}
 
	cout << r + 1 << " " << m << endl;
	rep(i, m){
		cout << v[i].u << " " << v[i].v << " " << v[i].cost << endl;
	}
 
}