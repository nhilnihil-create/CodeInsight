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
signed main(){
	string s;
	cin>>s;
	n=s.size();
	int f[26]={0},alluse=1;
	rep(i,n){
		f[s[i]-'a']=1;
		//cout<<s[i]-'a'<<endl;
	}
	rep(i,26){
		if(!f[i])alluse=0;
	}
	//rep(i,26)cout<<'a'+i<<f[i]<<endl;
	if(s=="zyxwvutsrqponmlkjihgfedcba"){
		cout<<-1<<endl;
		return 0;
	}
	if(alluse){
		int place;
		for(int i=n-1;i>=1;i--){
			if(s[i-1]<s[i]){
				place=i;
				break;
			}
		}
		//cout<<place<<endl;
		int mins=INF;;
		for(int i=n-1;i>=place;i--){
			if(s[i]>s[place-1])mins=std::min(mins,(int)s[i]);
		}
		s[place-1]=(char)mins;
		rep(i,place){
			cout<<s[i];
		}
		cout<<endl;
	}
	else{
		char c;
		rep(i,26){
			if(!f[i]){c='a'+i;break;}
		}
		cout<<s<<c<<endl;
	}
}
