       
   //                                                  '-.-'
   //                                         ()      __.'.__
   //                                      .-:--:-.  |_______|
   //                               ()      \____/    \=====/
   //                               /\      {====}     )___(
   //                    (\=,      //\\      )__(     /_____\
   //    __    |'-'-'|  //  .\    (    )    /____\     |   |
   //   /  \   |_____| (( \_  \    )__(      |  |      |   |
   //   \__/    |===|   ))  `\_)  /____\     |  |      |   |
   //  /____\   |   |  (/     \    |  |      |  |      |   |
   //   |  |    |   |   | _.-'|    |  |      |  |      |   |
   //   |__|    )___(    )___(    /____\    /____\    /_____\
   //  (====)  (=====)  (=====)  (======)  (======)  (=======)
   //  }===={  }====={  }====={  }======{  }======{  }======={
   // (______)(_______)(_______)(________)(________)(_________)
   //
   // Credits :- Joan G. Stark
   //|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
   //|                      AUTHOR - KASPAROVIAN                                     |
   //|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define frr(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fr first
#define sc second
#define int long long
#define mk make_pair
#define endl '\n'
#define MOD 1000000007
#define in insert
#define sz(x) (ll)(x).size()
#define mem(a,b) memset(a,b,sizeof(a))
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
typedef vector<vi> graph;
template<class T> void mxi(T & a, const T & b) { a = max(a, b); }
template<class T> void mni(T & a, const T & b) { a = min(a, b); }
ld EPS=1e-9;
int n;
int mat[22][22];
int dp[21][1<<21];
int go(int id,int mask)
{
	if(id==n)
	{
		if(mask==(1<<n)-1)
			return 1;
		else
			return 0;
	}
	if(dp[id][mask]!=-1)
		return dp[id][mask];
	int &s=dp[id][mask];
	s=0;
	for(int i=0;i<n;i++)
	{
		if(mat[id][i]==1&&(mask&(1<<i))==0)
		{
			s=(s+go(id+1,mask|(1<<i)))%MOD;
		}
	}
	return s;
}
void solve()
{
	mem(dp,-1);
	cin>>n;
	frr(i,n)
	frr(j,n)cin>>mat[i][j];
	cout<<go(0,0)<<endl;

}
signed main()
{
  fast;
  int t,tab;
  t=1;
  tab=t;
  while(t--)
  {
    //cout<<"Case #"<<(tab-t)<<": ";
    solve();
  }
}