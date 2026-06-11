#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define all(t) (t).begin(),(t).end()
#define MOD 1000000007
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}

int n,m;


vector<int> g[100010];
int h[100010]={0};

int main(){
	
	cin >> n >> m;
	FOR(i,n+m-1){
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		h[b]++;
	}

	stack<int> st;
	int ans[100010];

	FOR(i,n)if(h[i]==0)st.push(i);
	int cnt=0;
	while(!st.empty()){
		int p=st.top();st.pop();
		if(cnt==0)ans[p]=0;
		FOR(i,g[p].size()){
			h[g[p][i]]--;
			if(h[g[p][i]]==0){st.push(g[p][i]);ans[g[p][i]]=p;}
		}
		cnt++;
	}

	FOR(i,n){
		cout << ans[i+1] << endl;
	}
}

