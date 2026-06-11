#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v(n+2, 0);
	rep(i,1,n+1)cin >> v[i];
	int cst = 0;
	rep(i,0,n+1)cst += abs(v[i+1] - v[i]);
	rep(i,1,n+1){
		cout << cst - abs(v[i-1] - v[i]) - abs(v[i+1] - v[i]) + abs(v[i-1] - v[i+1]) << '\n';
	}
}
