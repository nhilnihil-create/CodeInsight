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
const char a[5]={'M','A','R','C','H'};
int main(){
	int n;
	cin>>n;
	map<char,ll> m;
	rep(i,n){
		string s;
		cin>>s;
		m[s[0]]++;
	} 
	ll ans=0;
	rep(i,5){
		REP(j,i+1,5){
			REP(k,j+1,5){
				ans+=m[a[i]]*m[a[j]]*m[a[k]];
			}
		}
	}
	cout<<ans<<endl;
	re 0;
}