#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=1000000007;
string s;

ll dp[3030][3030];
ll sump[3030][3030];

ll f(ll x, ll y){
	ll &r=dp[x][y];
	if(r>=0)return r;
	if(x==1&&y==0){
		r=1; return r;
	}
	if(s[x-2]=='<'){
		r=sump[x-1][y]; return r;
	}
	r=(sump[x-1][x-1]-sump[x-1][y]+MOD)%MOD; return r;
}

int main(){FIN;
	ll n; cin>>n;
	cin>>s;
	mset(dp,-1);
	fore(i,1,n+1){
		fore(j,0,i+1){
			sump[i][j+1]=sump[i][j]+f(i,j);
			if(sump[i][j+1]>MOD)sump[i][j+1]-=MOD;
		}
	}
	ll res=0;
	fore(i,0,n){
		res+=f(n,i);
		if(res>MOD)res-=MOD;
	}
	/*fore(i,1,n+1){
		fore(j,0,i){
			cout<<f(i,j)<<" ";
		}
		cout<<"\n";
	}
	fore(i,1,n+1){
		fore(j,0,i+2){
			cout<<sump[i][j]<<" ";
		}
		cout<<"\n";
	}*/
	cout<<res;
	return 0;
}