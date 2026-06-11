#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define gadd(x,y) x=add(x,y)
#define gmul(x,y) x=mul(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	string s;
	cin >> n >> s;
	int to = 0;
	int ans = 3e5 + 5;
	rep(i,0,n)to += s[i] == 'E'; 	
	
	rep(i,0,n){
		gmin(ans, to);
		to += s[i] == 'E' ? -1:1;
	}
	gmin(ans, to);
	
	cout << ans << '\n';
}
