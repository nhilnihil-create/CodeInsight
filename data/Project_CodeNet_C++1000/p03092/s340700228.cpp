#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const LL INF=1e18;
int n,A,B,a[5555],s[5010][5010];
LL f[5555],ans;
int main(){
	cin>>n>>A>>B;
	FOR(i,1,n) getint(a[i]);
	FOR(i,1,n){
		FOR(j,1,n) s[i][j]=s[i-1][j];
		FOR(j,a[i],n) s[i][j]++;
	}
	f[0]=0;
	FOR(i,1,n){
		f[i]=INF;
		FORD(j,i-1,0){
			//j+1..i-1
			if (a[i]<a[j]) continue;
			f[i]=min(f[i],f[j]+1ll*(i-j-1-(s[i-1][a[i]]-s[j][a[i]]))*A+1ll*(s[i-1][a[j]]-s[j][a[j]])*B+1ll*(s[i-1][a[i]]-s[i-1][a[j]]-s[j][a[i]]+s[j][a[j]])*min(A,B));
		}
	}
	ans=INF;
	FOR(i,1,n){
		ans=min(ans,f[i]+1ll*B*(s[n][a[i]]-s[i][a[i]])+1ll*((n-i)-s[n][a[i]]+s[i][a[i]])*min(A,B));
	}
	cout<<ans<<endl;
	return 0;
}