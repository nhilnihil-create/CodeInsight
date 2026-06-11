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

int n,ans,k;
int f[111][111];
vector<P> v;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		if(n%2==0){
			for(int j=1;j<=n;j++){
				f[j][i]=1;
				if(i==j||f[i][j])continue;
				if(n+1-i!=j)v.push_back(P(i,j));
			}
		}
		else{
			if(i==n){
				for(int j=1;j<=n;j++){
					f[j][i]=1;
					if(i==j||f[i][j])continue;
					v.push_back(P(i,j));
				}
			}
			else{
				for(int j=1;j<=n;j++){
					f[j][i]=1;
					if(i==j||f[i][j])continue;
					if(n-i!=j)v.push_back(P(i,j));
				}
			}
		}
	}
	cout<<v.size()<<endl;
	rep(i,v.size()){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
}
