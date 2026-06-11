// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

ll INF=LLONG_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int x,y,z,k;
	cin >> x >> y >> z >> k;
	vll a(x), b(y), c(z);
	for(int i=0; i<x; i++)cin >> a[i];
	for(int i=0; i<y; i++)cin >> b[i];
	for(int i=0; i<z; i++)cin >> c[i];
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	sort(c.rbegin(),c.rend());
	using T = tuple<ll, int,int,int>;
	using T2 = tuple<int,int,int>;
	priority_queue<T>pq;
	set<T2>st;
	pq.emplace(a[0]+b[0]+c[0],0,0,0);
	st.emplace(0,0,0);
	for(int t=0; t<k; t++){
		ll sum; int i,j,kk;
		tie(sum,i,j,kk)=pq.top();
		pq.pop();
		cout << sum << endl;
		if(i<x-1 && !st.count(T2(i+1,j,kk))){
			pq.emplace(a[i+1]+b[j]+c[kk],i+1,j,kk);
			st.emplace(i+1,j,kk);
		}
		if(j<y-1 && !st.count(T2(i,j+1,kk))){
			pq.emplace(a[i]+b[j+1]+c[kk],i,j+1,kk);
			st.emplace(i,j+1,kk);
		}
		if(kk<z-1 && !st.count(T2(i,j,kk+1))){
			pq.emplace(a[i]+b[j]+c[kk+1],i,j,kk+1);
			st.emplace(i,j,kk+1);
		}
	}
	return 0;
}	
	
