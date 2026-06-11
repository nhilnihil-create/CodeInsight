                                    #include<bits/stdc++.h>
                                    using namespace std;

                                    #define FOR(i,a,b) for(int i = (a); i < (b); i++)
                                    #define rep(i,n) FOR(i,0,n)
                                    #define RFOR(i,b,a) for(int i = (b) - 1; i>= (a); i--)
                                    #define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
                                    #define FILL(a, value) memset(a, value, sizeof(a)

                                    #define SZ(a) (int)a.size()
                                    #define ALL(a) a.begin(), a.end()
                                    #define PB push_back
                                    #define MP make_pair
                                    #define er erase
                                    #define in insert
                                    #define f first
                                    #define s second




                                    typedef  long long LL;
                                    typedef vector<int> VI;
                                    typedef vector<LL > VL;
                                    typedef vector<vector<int > > VVI;
                                    typedef vector<vector<LL>> VVL;
                                    typedef vector <vector<pair<int, int >> >VVPI;
                                    typedef vector<vector<pair<LL, LL >> >VVPL;
                                    typedef vector<pair<LL, LL >> PL;
                                    typedef vector<PL> VPL;
                                    typedef pair<int, int> PII;
                                    typedef pair<LL,LL > PLL ;
                                    typedef vector<PII> VPI;

                                    const double PI = acos(-1.0);
                                    const int INF = 1e9;
                                    const LL LINF = (LL)1e18;

                                    const double EPS = 1e-7;
                                    const int MAS =  3 *1e5 + 10;
                                    const int mod = 998244353;
                                    const int MOD =1e9+7;
                                    const int LOG= 19;
                                    const int ar = 1e5 +100;
                                    const int MAX = 1e6 + 1e2;
                                vector<vector<int >> a;
                                VL preculc;
                                vector<LL > dp ;
                                void rec(int i,const vector<int >& not_taken ,LL score_already,int mask ,int groups)
                                {
                                    if(i == SZ(not_taken))
                                    {
                                        dp[mask] = max(dp[mask],score_already + preculc[groups]);
                                        return ;
                                    }
                                    rec(i + 1, not_taken ,score_already, mask,groups);
                                    rec(i + 1, not_taken ,score_already,mask ^ (1 << not_taken[i]),groups ^ ( 1 << not_taken[i]));

                                }

                                int main() {
                                    ios_base::sync_with_stdio(false);
                                    cin.tie(NULL);
                                    int n;
                                    cin >> n;
                                    a.resize(n);
                                    rep(i,n)a[i].resize(n);
                                    rep(i,n)rep(j,n)cin >> a[i][j];
                                    dp.resize(1 << n , -INF);
                                    preculc.resize(1 << n,0);
                                    rep(mask ,(1 << n ))
                                    {
                                        rep(i,n)
                                        {
                                            if(mask & ( 1 << i))
                                            {
                                                FOR(j,i + 1 ,n )
                                                {
                                                    if(mask & ( 1 << j))
                                                    {
                                                        preculc[mask]+=a[i][j];
                                                    }
                                                }
                                            }
                                        }

                                    }
                                    dp[0] = 0 ;
                                    rep(mask,(1 << n))
                                    {
                                        VI not_taken;
                                        rep(i,n)
                                        {
                                            if(!(mask & ( 1 << i)))not_taken.PB(i);
                                        }
                                        rec(0,not_taken,dp[mask],mask,0);
                                    }

                                    cout << dp[(1 << n) -1];

                                    



                                }















































