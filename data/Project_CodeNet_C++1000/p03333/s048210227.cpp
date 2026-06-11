#include <bits/stdc++.h>
using namespace std;
/*---define tricks---*/
#define ALL(v) v.begin(),v.end()
#define UN(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(x,y) memset(x,y,sizeof(x))
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rsort(v) sort(ALL(v)),reverse(ALL(v))
/*---define types---*/
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
/*---define variables---*/
int n;
ll ans;
vi L,R;
/*---define function---*/

/*---main code---*/
int main()
{
	FIO;
	cin>>n;
	L.resize(n+1),R.resize(n+1);
	for(int i=0;i<n;++i)
	{
		cin>>L[i]>>R[i];
	}
	rsort(L),sort(ALL(R));
	for(int i=0;i<n;++i)
	{
		if(L[i]>R[i])
		{
			ans+=(L[i]-R[i])*2;
		}
	}
    cout<<ans<<'\n';
	return 0;
}
