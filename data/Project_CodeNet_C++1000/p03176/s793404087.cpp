//****** @mdazmat9 **********
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define EB emplace_back
#define PB push_back
#define endl "\n"
#define MOD 1000000007
#define MOD2 998244353
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
typedef pair<int, int> pr;
typedef vector<int> VI;
typedef vector<pr> VP;
typedef vector<string> VS;
typedef vector<vector<int>> VV;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define trace(v) for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";cout<<endl;
const int inf = 1e17;
int fast_pow(int x, int y, int p);
const int sz = 300001;
int st[4*sz];
int n;

void update(int ss, int se, int i, int val, int si){
	if (i < ss || i > se){
		return;
	}
	if (ss==se)
	{
		st[si] = val;
		return ;
	}
	int mid = (ss+se)/2;

	if (i >= ss && i <= mid)
		update( ss, mid, i,val, 2 * si + 1);
	else
		update( mid + 1, se,i, val, 2 * si + 2);

	st[si] = max(st[2 * si + 1],st[2 * si + 2]);
}

int get_max(int ss, int se, int qs, int qe, int si){
	if (qs <= ss && qe >= se)
		return st[si];
	if (se < qs || ss > qe)
		return 0;
	int mid = (ss+se)/2;
	return max(get_max(ss, mid, qs, qe, 2 * si + 1) ,get_max(mid + 1, se, qs, qe, 2 * si + 2));
}



void solve() {
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	int ans = 0;
	for(int i=0;i<n;i++){
		int left = get_max(0,n-1,0,a[i]-1,0);
		ans = max(ans,left+b[i]);
		update(0,n-1,a[i],left+b[i],0);
	}
	cout<<ans<<endl;

}


int32_t main() {

	IOS;
	int test = 1;
	// cin>>test;
	for (int i = 1; i <= test; i++) {
        // cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
int fast_pow(int x, int y, int p) {
	int res = 1;
	x = x % p;
	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}