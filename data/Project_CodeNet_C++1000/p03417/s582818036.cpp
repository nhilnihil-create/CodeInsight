#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) (a).size() 
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,n) for(int i=1;i<=n;i++)
#define ford(i,n) for(int i=n;i>=0;i--) 
#define REP(i,a,n) for(int i=a;i<n;i++)
#define foreach(itr,c) for(__typeof((c).begin(),(c).end())itr=c.begin();itr!=c.end();itr++) 
#define fill(a,b) memset(a,b,sizeof(a))
#define re return
#define INF 1e9
#define LINF 1e18
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi > vpi; 
int main(){
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	ans+=max(n-2,0ll)*max(m-2,0ll);
	if(n==1&&m==1){
		ans+=1;
	}
	else if(n==1){
		ans+=m-2;
	}
	else if(m==1){
		ans+=n-2;
	}
	cout<<ans;
	re 0;
}