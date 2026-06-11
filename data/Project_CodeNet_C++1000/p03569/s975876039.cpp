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
#define INF 1000000007
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

int ans;
int n,m;

signed main(){
	string s,t,kt;
	cin>>s;
	rep(i,s.size()){
		if(s[i]!='x')t+=s[i];
	}
	kt=t;
	reverse(t.begin(),t.end());
	if(t!=kt){
		cout<<-1<<endl;
		return 0;
	}
	int i=0,j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j]){
			ans++;
			if(s[i]=='x')i++;
			else j--;
		}
		else{
			i++;j--;
		}
	}
	cout<<ans<<endl;

}
