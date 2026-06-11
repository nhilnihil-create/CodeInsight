#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#define de(x) cout<<#x<<"="<<x<<endl
	#define rff freopen("input.txt","r",stdin)
	#include "Debug.h"
#else
	#define de(x)
	#define rff
#endif

#define itr(x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();it++)
#define For(i,n) for (int i=1;i<=(int)(n);i++)
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define all(x) (x).begin(),(x).end()
#define PQ priority_queue
#define pii pair<int,int>
#define vi vector <int>
#define ll long long
#define pb push_back
#define mp make_pair
#define re return
#define se second
#define fi first
const int INF=0x7fffffff;
const int MAXN=+3;

int n;
vi g[1003];

void solve(){
	int INDEX=1;
	For(i,n){
		for (int j=i+1;j<=n;j++){
			g[i].pb(INDEX);
			g[j].pb(INDEX);
			INDEX++;
		}
	}
	cout<<"Yes"<<endl<<n<<endl;
	For(i,n){
		cout<<n-1<<" ";
		for (int j:g[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	exit(0);
}

int main(){
	cin>>n;
	For(i,1000){
		if (i*(i+1)/2==n){
			n=i+1;
			solve();
		}
	}
	cout<<"No";
}