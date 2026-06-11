#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i=a; i < n; i++)
typedef long long int lli;
typedef long double Double;
typedef pair<int,int> pii;
typedef vector<lli> vi;
typedef vector<vi> vvi;
const int mod = 1e9+7;
#define MAXN 200005
lli st[4*MAXN];

void update(int pos, int ini, int fin, int idx, lli val){
	if(fin < idx || ini > idx) return;

	if(fin == idx && ini == idx){
		st[pos]+=val;
		return;
	}

	int m = (ini+fin)/2;
	update(2*pos+1,ini,m,idx,val);
	update(2*pos+2,m+1,fin,idx,val);
	st[pos] = max(st[2*pos+1],st[2*pos+2]);
}

lli query(int pos, int l ,int r, int ini ,int fin){
	if(fin < l || ini > r){
		return -1;
	}

	if(ini >= l && fin <= r){
		return st[pos];
	}

	int m = (ini+fin)/2;
	return max(query(2*pos+1,l,r,ini,m),query(2*pos+2,l,r,m+1,fin));
}

int main(){__
	int n;
	cin >> n;
	vi a(n),b(n);
	for(int i=0; i < n; i++) cin >> a[i];
	for(int i=0; i < n; i++) cin >> b[i];

	for(int i =0; i < n; i++){
		int x = a[i]-1;
		lli best =0ll;
		if(x != 0){
			best = query(0,0,x-1,0,n-1);
		}
		update(0,0,n-1,x,best+b[i]);
	}

	cout << query(0,0,n-1,0,n-1) << endl;
	return 0;
}
