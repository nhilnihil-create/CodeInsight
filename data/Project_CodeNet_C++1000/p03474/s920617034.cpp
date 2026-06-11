#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
// }}} End Header

int main() {
	int a, b, flag=0;
	cin >> a >> b;
	string s;
	cin >> s;
	rep(i,a){
		if(!(s[i]>='0' && s[i]<='9')) flag++; 
	}
	if(s[a] != '-') flag++;
	loop(i, a+1, s.length()){
		if(!(s[i]>='0' && s[i]<='9')) flag++;
	}
	puts(flag==0? "Yes" : "No");
	return 0;
}