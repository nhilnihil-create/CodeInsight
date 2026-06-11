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

	int n, m, x, k;
	cin >> n >> m;
	vector<int> food(m);
	forn(i, 0, n){
		cin >> k;
		forn(j, 0, k){
			cin >> x;
			x--;
			food[x]++;
		}
	}
	int ans = 0;
	forn(i, 0, m)if(food[i] == n)ans++;
	cout << ans << endl;


}


