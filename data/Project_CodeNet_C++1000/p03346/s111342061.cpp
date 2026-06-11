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

int ans=INF;
int n,m;
int a[211111];//iの順番
signed main(){
	
	cin>>n;
	rep(i,n){
		int num;
		cin>>num;
		a[num-1]=i;
	}
	int cnt=0;
	rep(i,n){
		if(a[i]<a[i+1])cnt++;
		else{
			cnt++;
			ans=min(ans,n-cnt);
			cnt=0;
		}
	}
	ans=min(ans,n-cnt);
	
	cout<<ans<<endl;
	
}
