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
bitset<4010000> B;
int n,a[2020],csu = 0;
int main() {
	B[0] = 1;
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		csu+=a[i];
		B|=(B<<(a[i]));
	}
	for(int i=(csu+1)/2;;i++){
		if(B[i]){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
