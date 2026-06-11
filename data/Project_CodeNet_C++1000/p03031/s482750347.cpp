#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
	#define debug(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define debug(...) 42
#endif

#define sf scanf
#define pf printf
#define nl printf("\n")
#define ps(s) printf("%s",s.c_str())
#define mem(x,val) memset(x,val,sizeof x)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend() 
#define sz(x) (int)(x).size()
#define test_case int ___t;scanf("%d", &___t);for(int cs=1;cs<=___t;cs++)

inline string getString(int n){char ch[n+5];sf(" %s",ch);return string(ch);}
inline string getLine(int n)
{char ch[n+5];fgets(ch,n+5,stdin);string s=string(ch);s.pop_back();return s;}

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;
typedef long long ll;

const int S=100100;
int main()
{
	int n,m;
	while(~sf("%d %d",&n,&m))
	{
		vector<int>g[m+5];
		for(int i=0;i<m;i++)
		{
			int k;
			sf("%d",&k);
			for(int j=0;j<k;j++)
			{
				int x;
				sf("%d",&x);
				x--;
				g[i].push_back(x);
			}
		}

		int p[m+5];
		for(int i=0;i<m;i++)sf("%d",&p[i]);

		int ans=0;
		for(int i=0;i<(1<<n);i++)
		{
			bool all=true;
			for(int j=0;j<m;j++)
			{
				int cnt=0;
				for(int light:g[j])
				{
					if((i & (1<<light))!=0)cnt++;
				}
				if(cnt%2!=p[j]%2)
				{
					all=false;
					break;
				}
			}
			if(all)ans++;
		}
		pf("%d\n",ans);
	}
    return 0;
}

































