#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout<<(#x)<<"="<<(x)<<endl
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.14159265358979323846264338327
#define INF 0x3f3f3f3f
#define MOD 998244353
#define pqueue priority_queue
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef unsigned long long ull;

#define MAXN 100005

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n; cin>>n;
  string s; cin>>s;
  int rc=0,bc=0;
  forn(i,0,n){
   if(s[i]=='R') rc++;
    else bc++;
  }
  if(rc>bc) cout<<"Yes\n";
  else cout<<"No\n";
	
	return 0;
}
