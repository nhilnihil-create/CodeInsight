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

int n,a[30030],taken[30030] = {0};
int main() {
	read(n);
	if(n == 3){
		cout<<"2 5 63\n";
		return 0;
	}
	if(n%2 == 1){
		cout<<30000<<' ';
		n-=1;
	}
	n/=2;
	int typ = 0;
	int p1 = 2,p2 = 3,a = 0,t = 0;
	for(int j=1;j<=n;j++){
		if(p1+2<30000 && t !=0){
			cout<<p1<<' '<<p1+2<<' ';
			p1+=6;
		}else{
			t = 1;
			cout<<p2<<' '<<p2+6<<' ';
			p2+=3;
			if(a)p2+=6;
			a^=1;
		}
		typ^=1;
	}
	cout<<endl;
	return 0;
}
