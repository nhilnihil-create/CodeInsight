#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n; cin >> n;
	vll a(n),b(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	vi c(n); rep(i,n) c[i]=b[i]-a[i];
	ll pos=0;
	ll neg=0;
	rep(i,n){
		if(c[i]>0) pos+=c[i]/2;
		else neg += c[i];
	}
	 if(pos+neg>=0) cout << "Yes" << endl;
	else cout << "No" << endl;
}


