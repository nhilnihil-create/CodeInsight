#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int T;

ll a,b,c,d;
bool solve(){
	read(a);read(b);read(c);read(d);
	if(a<b || b>d)return false;
	if(c+1>=b) return true;
	ll cp = ((a-b)+b-c-1)%b,diff = d%b;
	ll cd = __gcd(diff,b);
	ll ub = b-c-1;
	ll minp = cp%cd;
	return (minp>=ub);
}

int main() {
	read(T);
	while(T--){
		if(solve()){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
