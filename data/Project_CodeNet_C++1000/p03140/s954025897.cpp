#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int n;cin>>n;
	int ans = 0;
	string a,b,c;cin>>a>>b>>c;
	for(int i = 0; i < n; i++) {
		if (a[i] == b[i] && b[i] == c[i])continue;
		else if (a[i] == b[i] || a[i] == c[i] || b[i] == c[i])ans++;
		else ans += 2;
	}
	cout << ans << endl;
	return 0;
}