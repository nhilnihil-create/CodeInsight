#include <iostream>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
using namespace std;

typedef long long ll;

#define INF 100000000;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = n - 1; i >= 0; i--)
#define eps 1.0e-14;

using pint = pair<ll,ll>;

int main(){
	int n,q; cin >> n >> q;
	string s; cin >> s;
	int l[100006],r[100006];
	rep(i,q) cin >> l[i] >> r[i];
	vector<int> vec(n+1,0);//1_indexed
	rep(i,n){
		int cal = 0;
		if(s[i-1] == 'A' && s[i] == 'C' && i != 0) cal++;
		//cout << cal << endl;
		vec[i+1] = vec[i] + cal;
	}
	//vec[n] = vec[n-1];
	rep(i,q){
		cout << vec[r[i]] - vec[l[i]] << endl;
	}
	return 0;
}