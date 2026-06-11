#include <bits/stdc++.h>
typedef long long ll;
#define  rep(i,a,b)for(long long i=a;i<b;++i)
#define  rrep(i,a,b)for(int i=a;i>=b;--i)
#define  yesno(flag)if(flag)cout<<"Yes"<<endl; else cout<<"No"<<endl;
using namespace std;
const int INF=100000000LL;
const ll r197=1000000007;
typedef pair<ll,ll>P;
typedef pair<P,P>Pa;
vector<ll> v[100001];
ll C[100001];
struct edge{ll time,posi,abe,he;};
ll h,w;
char a[1001][1001];
int c[1001][1001];
int dp[1001][1001][16];
int main() {
	int n;
	cin>>n;
	int i=1;
	bool b=false;
	while(1){
		if((i*(i+1))/2==n){
			cout<<"Yes"<<endl;
			cout<<i+1<<endl;
			int h=1,ky=0,kx=0;
			while(1){
				if(kx>=n||ky>=n)break;
				int s=h;
				rep(j,0,i-kx){
					c[ky][kx+j]=h;
					h++;
				}
				h=s;
				ky++;
				rep(j,0,i-ky+1){
					c[ky+j][kx]=h;
					h++;
				}
				kx++;
			}
			rep(j,0,i+1){
				cout<<i;
				rep(k,0,i)cout<<" "<<c[j][k];
				cout<<endl;
			}
			break;
		}
		if((i*(i+1))/2>n){
			b=true;
			break;
		}
		i++;
	}
	if(b)cout<<"No"<<endl;
}
