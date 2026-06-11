#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 2000000007
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 0
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int ceil2(int a,int b){if(a%b){return a/b+1;}else{return a/b;}}
using namespace std;

int n,ans;
int a[211111];
signed main(){
	cin>>n;
	rep(i,n){
		cin>>a[i];
	}
	int rig=0,sum=0,xorsum=0;
	for(int lef=0;lef<n;lef++){
		while(rig<n && (sum+a[rig]==(xorsum^a[rig]))){
			sum+=a[rig];
			xorsum^=a[rig];
			rig++;
		}
		ans+=rig-lef;
		if(lef==rig)rig++;
		else{
			sum-=a[lef];
			xorsum^=a[lef];
		}
	}
	cout<<ans<<endl;
}
