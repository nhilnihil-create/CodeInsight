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

ll l = 2,r = 2;

int k,a[100010];

int main() {
	read(k);
	for(int i=0;i<k;i++){
		read(a[i]);
	}
	for(int i=k-1;i>=0;i--){
		l = (l+a[i]-1)/a[i];
		r = r/a[i];
		
		if(l>r){
			cout<<-1<<endl;
			return 0;
		}else{
			l = l*a[i];
			r = r*a[i]+a[i]-1;
		}
	}
	cout<<l<<' '<<r<<endl;
	return 0;
}
