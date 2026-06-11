    #include <bits/stdc++.h>

    using namespace std;

    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define FOR(i,a,b) for(int i = (a); i < (b); i++)
    #define rep(i,n) FOR(i,0,n)
    #define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
    #define SZ(a) (int)a.size()
    #define ALL(a) a.begin(),a.end()
    #define PB push_back

    typedef long long LL;

    const double PI = acos(-1.0);
    const int INF = 1000 * 1000 * 1000 + 7;
    const LL LINF = INF * (LL)INF;
    const int MAS =4e5; //5;
    const int MOD = 1e9 + 7;
    const double EPS = 1e-8;


    int main() {
        IOS
        //   freopen("series.in","r",stdin);
        //   freopen("series.out","w",stdout);
        int n ;
        cin >> n ;
        string s;
        cin >> s;
        vector<vector<int >> dp(n + 10 ,vector<int > (n + 10 ) );
        dp[1][1] = 1;
        FOR(len,2,n + 1)
         {
            vector<int > pref(len);

            FOR(i,1,len)
            {
               pref[i] = (pref[i-1] + dp[len-1][i] )%MOD ;
            }

            FOR(newdigit,1,len + 1)
            {
               int l,r;
               if(s[len-2] == '<')
               {
                   l =1 ;
                   r =  newdigit - 1;
               }
               else
               {
                   l = newdigit  ;
                   r = len -1;
               }
               if( l  <=r)
               {
                  dp[len][newdigit]+= ( pref[r] - pref[l-1] + MOD  ) %MOD ;
               }
            }
        }
        LL ans = 0 ;
        FOR(i,1,n + 1)
        {
            ans+=dp[n][i];
        }
        cout << ans%MOD;

    }