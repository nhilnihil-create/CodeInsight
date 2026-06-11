#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<pair<string, pii> > r(n);
	forn(i, 0, n){
		cin >> r[i].F >> r[i].S.F;
		r[i].S.F *= -1;
		r[i].S.S = i+1;
	}
	sort(r.begin(), r.end());
	for(auto x: r){
		cout << x.S.S << endl;
	}


}

