#include <bits/stdc++.h>

#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

char Mp[660][660];


int n;
int main() {
	read(n);
	for(int i=0;i<n;i++){
		cin>>Mp[i];
	}
	int ans = 0;
	for(int a=0;a<n;a++){
		int ad = n;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(Mp[(i+a)%n][j]!=Mp[(j+a)%n][i])ad = 0;
			}
		}
		ans+=ad;
	}
	cout<<ans<<endl;
	return 0;
}
