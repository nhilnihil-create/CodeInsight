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


                        LL dp[MAS];
                        int n;
                        LL t[MAS];
                        LL get(int r)
                        {
                          LL res = 0;
                          for(;r >= 0 ; r = (r &(r + 1))-1 )res = max(res,t[r]);
                          return res;
                        }
                        void upd(int pos, LL val) {
                            for (; pos < n; pos |= pos + 1)t[pos] = max(t[pos], val);
                        }

                        int main() {
                            ios_base::sync_with_stdio(false);
                            cin.tie(NULL);
                            cin >> n ;
                            VL h(n),score(n);
                            rep(i,n)cin >> h[i];
                            rep(i,n)cin >> score[i];
                            rep(i,n)
                            {
                                LL best = get(h[i] - 1);
                                dp[h[i]] = best + score[i];
                                upd(h[i],dp[h[i]]);

                            }
                            cout <<*max_element(dp , dp+ MAS - 10 );

                        }















































