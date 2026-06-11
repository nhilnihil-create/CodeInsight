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

int n,m,k,ans;
vector<int> a,v;
signed main(){
	
	cin>>n;
	rep(i,n){
		int num;
		cin>>num;
		a.push_back(num);
	}
	rep(k,n){
		int keep=-1,j=0;
		rep(i,a.size()){
			if(i+1==a[i]){
				keep=a[i];
			}
		}
		if(keep!=-1){
			v.push_back(keep);
			a.erase(a.begin()+keep-1);
		}
	}
	if(a.size()==0){
		repb(i,n)cout<<v[i]<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	
	
}
