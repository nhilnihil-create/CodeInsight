#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define rep(i,x) for(int (i)=1;(i)<=(x);(i)++)
#define repp(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
#define forn(i,x) for(int (i)=0;(i)<(x);(i)++)
#define foreach(i,x) for(auto (i):(x))
using namespace std;
typedef pair<int,int>pii;
LL n,p,ans=1;
bool pr[1000010];
void init(int x){
	memset(pr,true,sizeof(pr));
	pr[1]=0;
	for(LL i=2;i*i<=x;i++)
		if(pr[i])
			for(LL j=2;i*j*i*j<=x;j++)
				pr[i*j]=0;
}
int main(){
	cin>>n>>p;
	if(n==1){
		cout<<p<<endl;
		return 0;
	}
	init(p);
	for(LL i=2;i*i<=p;i++){
		if(pr[i]&&p%i==0){
			LL tp=0;
			while(p%i==0)p/=i,tp++;
			while(tp/n>0){
				ans*=i,tp-=n;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
