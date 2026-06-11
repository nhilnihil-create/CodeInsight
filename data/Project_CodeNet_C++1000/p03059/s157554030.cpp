#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define read(x) int x; cin>>x;
#define print(x) for(int i=0; i<(int) x.size(); i++) cout<<x[i]<<" "; cout<<endl;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;

const ll INFLL = (ll) 1e16;
const int INF = (int) 1e8;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	read(a) read(b) read(t)
	int ans = (t/a)*b;
	cout<<ans<<endl;
	
	return 0;
}
