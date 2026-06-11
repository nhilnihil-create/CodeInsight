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
                                                        #define sqr(x) ((x)*(x))





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
                                                        const int INF = 1e9 * 2;
                                                        const LL LINF = (LL)1e18 ;

                                                        const double EPS = 1e-7;
                                                        const int MAS =  3 *1e5 + 10;
                                                     //   const int mod = 998244353;
                                                        const int MOD =1e9+7;
                                                        const int LOG= 19;
                                                        const int ar = 1e5 +100;
                                                        const int MAX = 1e6 + 1e2;
                                                        const int root = 0;




                                                        bool comperator(pair<PII ,int >  a ,pair<PII,int > b)
                                                        {
                                                            return a.f.f + a.f.s < b.f.f + b.f.s ;
                                                        }
                                                        const int mx =20101;
                                                        int main() {
                                                            ios_base::sync_with_stdio(false);
                                                            cin.tie(NULL);
                                                            // freopen("horrible.in","r",stdin);
                                                            // freopen("horrible.out","w",stdout);
                                                            int n;
                                                            cin >> n;
                                                            vector<pair<PII,int >> items(n);
                                                            vector<LL > dp(20101);
                                                            rep(i,n)
                                                            {
                                                                cin >> items[i].f.f >> items[i].f.s >> items[i].s;
                                                            }
                                                            sort(ALL(items),comperator);
                                                            for(auto item : items)
                                                            {
                                                                for(int w =min(item.f.s,mx - item.f.f);w >=0 ; w--)
                                                                {
                                                                  dp[w + item.f.f] = max(dp[w + item.f.f],dp[w] + item.s);
                                                                }
                                                            }
                                                            cout << *max_element(ALL(dp));


                                                        }
