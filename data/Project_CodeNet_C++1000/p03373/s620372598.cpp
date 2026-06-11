#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define num(a) a-'0'
#define maxs(a,b) if(b>a)a=b
#define mins(a,b) if(b<a)a=b;
#define debug(x) cout<<#x<<":"<<x<<" "
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vl vector<long long int>
#define v vector
#define p pair
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define ln "\n"	
typedef long long int ll;
typedef long double ld;
typedef double d;
using namespace std;
ll modF=1e9+7;
ll INF=1e18;

void solve(){
	ll a,b,c,x,y;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);
	if(a + b > 2 * c){
		ll ans = min(x,y) * 2 * c;
		if(x > y){
			if(2 * c < a)
				ans += (x - y) * 2 * c;
			else
				ans += (x - y) * a;
		}
		else{
			if(2 * c < b)
				ans += (y - x) * 2 * c;
			else
				ans += (y - x) * b;
		}
		printf("%lld",ans);
	}
	else{
		ll ans = a * x + b * y;
		printf("%lld",ans);
	}
}

int main(){
	boost_io;
	solve();
	return 0;
}