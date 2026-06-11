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

struct St{
	int buff = 0;
	set<int> S;
	void add(int x){
		S.insert(x-buff);
	}
	int max(){
		return *S.rbegin()+buff;
	}
	int query(){
		while((*S.begin())+buff<0)S.erase(S.begin());
		S.insert(-buff);
		return S.size()-1;
	}
}SS;
ll ans = 0;
int n,a[200030];
int main() {
	read(n);
	SS.add(0);
	ll ans = 0;
	for(int i=0;i<n;i++)read(a[i]);
	if(a[0]!=0){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=n-1;i>=0;i--){
		if(SS.max()>a[i]){
			cout<<-1<<endl;
			return 0;
		}
		SS.add(a[i]);
		ans +=SS.query();
		SS.buff+=-1;
	}
	cout<<ans<<endl;
	return 0;
}
