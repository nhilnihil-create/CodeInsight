#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int x[2000],y[2000];
int xx[2000],yy[2000];
int dx[]{-1,1,1,-1},dy[]{-1,1,-1,1};
string s="LRDU";

int main(){
	int n;scanf("%d",&n);
	set<int>se;
	rep(i,n){
		scanf("%d%d",&x[i],&y[i]);
		se.insert(abs((x[i]+y[i])%2));
		xx[i]=x[i]-y[i];
		yy[i]=x[i]+y[i];
	}
	if(se.size()>1){
		puts("-1");return 0;
	}
	vector<ll>v;
	if(*se.begin()==0)v.push_back(1);
	rep(i,35){
		v.push_back(1LL<<i);
	}
	reverse(v.begin(),v.end());
	cout<<v.size()<<endl;
	rep(i,v.size()){
		printf("%lld ",v[i]);
	}
	puts("");
	rep(i,n){
		ll X=xx[i],Y=yy[i];
		string ans;
		for(ll d:v){
			int id=-1;
			rep(k,4){
				if(X*dx[k]>=0&&Y*dy[k]>=0)id=k;
			}
			X-=dx[id]*d;Y-=dy[id]*d;
			ans+=s[id];
		}
		printf("%s\n",ans.data());
	}
}