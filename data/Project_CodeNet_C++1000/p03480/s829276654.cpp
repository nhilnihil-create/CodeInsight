#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 100001
#define int ll
string str;
bool pos[maxn];

		
			
bool ok(int k){
	mem(pos,0);
	
	bool pos1 = 1, pos0 = 1;
	
	FOR(i,k-1,str.size() - k){
		pos[i] = 1;
	}
	
	FOR(i,0,str.size()-1){
		if (i >= k || i + 1 <= str.size() - k) pos[i] = 1;
		
		if (str[i] == '1') pos1 = pos1 && pos[i];
		else pos0 = pos0 && pos[i];
	}
	
	return pos1||pos0;
	
	
}
int32_t main(){
	fast;
	
	cin>>str;
	int N = str.size();
	bool one = 1,zr = 1;
	
	aFOR(i,str){
		if (i == '1') zr = 0;
		else one = 0;
	}
	
	if (zr || one){
		cout<<str.size();
		return 0;
	}
	
	
	int l = 0, r = str.size()+1;
	
	while (l+1<r){
		int mid = (l+r)/2;
		

		
		if (ok(mid)) l = mid;
		else r = mid;
	}
	
	cout<<max((ll)1,l);
	
}

