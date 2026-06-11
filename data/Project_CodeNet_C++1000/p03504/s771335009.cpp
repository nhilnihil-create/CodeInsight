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
#define INF 2000001145
#define LINF 100000000000000007
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
int ceil2(int a,int b){if(a%b){return a/b+1;}else{return a/b;}}
//typedef long long int ll;
typedef pair<int,int> P;
struct edge{int to,cost;};

int ans=0;
int n,C;
pair<P,int> p[111111];
int s[111111],t[111111],c[111111],ke[111];
int table[111111];
signed main(){
	cin>>n>>C;
	rep(i,n){
		int s,t,c;
		cin>>s>>t>>c;
		p[i]={{s,t},c};
	}
	sort(p,p+n);
	rep(i,n){
		if(ke[p[i].second]==p[i].first.first){
			table[p[i].first.first+1]++;
			table[p[i].first.second+1]--;
		}
		else{
			table[p[i].first.first]++;
			table[p[i].first.second+1]--;
		}
		ke[p[i].second]=p[i].first.second;
	}
	
	rep(i,100011){
		table[i+1]+=table[i];
	}
	rep(i,100011){
		ans=max(ans,table[i]);
	}
	cout<<ans<<endl;
}
