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

const int N = 2e5 +5;
int cnt[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	rep(i,0,n){
		int x;
		cin >> x;
		++cnt[x];
	}
	vector<array<int,2>> v;
	rep(i,0,N){
		if(cnt[i]){
			v.push_back(array<int,2>{cnt[i], i});
		}
	}
	sort(all(v));
	int ans = 0;
	rep(i,0,(int)v.size()-k){
		ans += v[i][0];	
	}
	cout << ans << '\n';
}
