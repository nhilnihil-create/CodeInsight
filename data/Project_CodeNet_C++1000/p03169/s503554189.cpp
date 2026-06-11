#include<bits/stdc++.h>
using namespace std;

#define double long double
#define int long long
#define ALL(x) x.begin(),x.end()
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb(x) push_back(x)
#define eb emplace_back
#define SORT(ls) sort(ls.begin(), ls.end())
#define DESC(ls) sort(ls.rbegin(), ls.rend()) 
#define mp(x, y) make_pair(x, y)
#define INF 1000000000
#define MOD 998244353 
#define F(i, a, n) for(i=a;i<n;i++)
#define SI(x) cin>>x
#define DI(x, y) cin>>x>>y
#define TI(x, y, z) cin>>x>>y>>z
#define FI(w, x, y, z) cin>>w>>x>>y>>z
#define SO(x) cout<<x<<"\n"
#define DO(x, y) cout<<x<<" "<<y<<"\n"
#define TO(x, y, z) cout<<x<<" "<<y<<" "<<z<< "\n"
#define FO(w, x, y, z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 303;
double E[N][N][N];

int32_t main(void)
{
    FASTER;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j;
    int n;
    SI(n);
    int co[3] = {0};
    F(i, 0, n)
    {
    	int x;
    	SI(x);
    	co[x - 1]++;
    }
    double nn = n;
    for(int c = 0; c + 1 < N; c++)
    {
    	for(int b = 0; b + 1 < N; b++)
    	{
    		for(int a = 0; a + 1 < N; a++)
    		{
    			double aa = a;
    			double bb = b;
    			double cc = c;
    			if(!a && !b && !c)
    				continue;
    			if(a + b + c > n)
    					continue;
    			if(a && b && c)
    			{
    				E[a][b][c] = (nn/(aa+bb+cc))*(1 + (aa/nn)*E[a - 1][b][c] + (bb/nn)*E[a + 1][b - 1][c] + (cc/nn)*E[a][b + 1][c - 1]);
    			}
    			else if(a && b)
    			{
    				E[a][b][c] = (nn/(aa+bb))*(1 + (aa/nn)*E[a - 1][b][c] + (bb/nn)*E[a + 1][b - 1][c]);
    			}
    			else if(b && c)
    			{
    				E[a][b][c] = (nn/(cc+bb))*(1 + (bb/nn)*E[a + 1][b - 1][c] + (cc/nn)*E[a][b + 1][c - 1]);
    			}
    			else if(c && a)
    			{
    				E[a][b][c] = (nn/(aa+cc))*(1 + (aa/nn)*E[a - 1][b][c] + (cc/nn)*E[a][b + 1][c - 1]);
    			}
    			else if(a)
    			{
    				E[a][b][c] = (nn/aa)*(1 + (aa/nn)*E[a - 1][b][c]);
    			}
    			else if(b)
    			{
    				E[a][b][c] = (nn/bb)*(1 + (bb/nn)*E[a + 1][b - 1][c]);
    			}
    			else if(c)
    			{
    				E[a][b][c] = (nn/cc)*(1 + (cc/nn)*E[a][b + 1][c - 1]);
    			}
    		}
    	}
    }
    cout << setprecision(13);
    cout << fixed << E[co[0]][co[1]][co[2]] << "\n";
    
    #ifdef LOCAL
    	cout<<endl<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
    #endif
    return 0;
}