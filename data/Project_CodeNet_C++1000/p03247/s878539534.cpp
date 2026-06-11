#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<double, double> P;

llint n;
llint x[1005], y[1005];
llint u[1005], v[1005];

void get(llint u, llint U[])
{
	u = (1LL<<39)-1 - u;
	for(int i = 0; i < 39; i++){
		if(u&(1LL<<(i+1))) U[i] = -1;
		else U[i] = 1;
	}
}

string calc(llint u, llint v)
{
	llint U[45], V[45];
	get(u, U), get(v, V);
	
	string ret;
	for(int i = 0; i < 39; i++){
		if(U[i] > 0){
			if(V[i] > 0) ret += "R";
			else ret += "U";
		}
		else{
			if(V[i] > 0) ret += "D";
			else ret += "L";
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	llint p = abs(x[1]+y[1]) % 2;
	for(int i = 1; i <= n; i++){
		if(abs(x[i]+y[i]) % 2 != p){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++) u[i] = x[i]+y[i], v[i] = x[i]-y[i];
	
	bool odd = (abs(u[1])%2);
	if(odd) cout << 39 << endl;
	else cout << 40 << endl;
	
	for(int i = 0; i < 39; i++) cout << (1LL<<i) << " ";
	if(!odd) cout << 1 << endl;
	cout << endl;
	
	for(int i = 1; i <= n; i++){
		if(!odd) u[i]--, v[i]--;
		string ans = calc(u[i], v[i]);
		if(!odd) ans += "R";
		cout << ans << endl;
	}
	
	return 0;
}