    #include <bits/stdc++.h>

    using namespace std;

  //  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define FOR(i,a,b) for(int i = (a); i < (b); i++)
    #define rep(i,n) FOR(i,0,n)
  //  #define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
  //  #define SZ(a) (int)a.size()
  //  #define ALL(a) a.begin(),a.end()
    #define PB push_back

    typedef long long LL;

    //const double PI = acos(-1.0);
    //const int INF = 1000 * 1000 * 1000 + 7;
    const LL LINF = 1e18 + 7;
   // const int MAS =4e5; //5;
   // const int MOD = 1e9 + 7;
    //const double EPS = 1e-8;


    vector<LL> pre ;
    vector<LL >dp;
    // O( 2^ n)
    void rec(int idx, const vector<int >& not_taken ,LL score,int mask, int group)
    {
        if (idx == (not_taken.size()))
        {
         dp[mask] = max(dp[mask],score  + pre[group]);
         return ;
        }
        rec(idx+1, not_taken , score,mask,group);
        rec(idx+1,not_taken , score,mask ^(1  << not_taken[idx]),group  ^ (1 << not_taken[idx ]));

    }
    int main() {

// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        //   freopen("series.in","r",stdin);
        //   freopen("series.out","w",stdout);
        int n;
        cin >> n;
        vector<vector<LL >>  a (n,vector < LL > (n))  ;
        rep(i,n) {
            rep(j, n)
            {
                cin >> a[i][j] ;
             }
        }
       // return 0;
       // cout << "runtime = " << clock()/1000.0 << endl;

       // return 0;
        pre.resize(1 << n);
       //  O(2^n * n ^ 2)
        rep(msk,(1 << n ))
        {
            rep(i,n)
            {
                if(msk & ( 1 <<i))
                {
                    for(int j =  i + 1; j < n ; j ++)
                    {
                        if(msk  & ( 1 << j))
                        {
                            pre[msk]+=a[i][j] ;
                        }
                    }
                }
            }
        }
        //O(n^2 * n )
        dp.resize(1 << n,-LINF );
        dp[0] = 0 ;
        rep(msk,(1 << n ))
        {
            vector<int> not_taken;
            rep(i,n)
            {
                if(!(msk & ( 1 << i)))
                {
                    not_taken.PB(i);
                }
            }
            rec(0,not_taken,dp[msk],msk,0);

        }
        cout << dp[(1 << n )- 1] << endl;



    }