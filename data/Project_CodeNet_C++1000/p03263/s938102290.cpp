#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         mapii      map<int,int>
#define         mapll      map<ll,ll>
#define         mapci      map<char,int>
#define         mapcl      map<char,ll>
#define         mapsi      map<string,int>
#define         mapsl      map<string,ll>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)
#define         lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
int ar[600][600];
int main()
{
     int i,j,k,n,x,m;

    cin >> n>>  m ;

    for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin >> ar[i][j];
    vector<pair<pii,pii>>ans;
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(ar[i][j]%2)
            {
                ar[i][j]--;
                ar[i+1][j]++;
                ans.pb({{i,j},{i+1,j}});
            }
        }
    }

    for(i=1;i<=m-1;i++)
    {
        if(ar[n][i]%2)
        {
            ar[n][i]--;
            ar[n][i+1]++;

            ans.pb({{n,i},{n,i+1}});
        }
    }
     
//     for(i=1;i<=n;i++)
//    {
//        for(j = 1;j<=m;j++)cout << ar[i][j]<<" ";
//
//        cout << endl;
//    }

    cout << ans.size() << endl;

    for(auto x : ans)cout << x.F.F << " " << x.F.S << " " << x.S.F << " " << x.S.S << endl;

  

//    ll cnt = 0;
//    for(i=0; i<n; i++)
//    {
//        cin >> ar[i];
//    }
//
//    for(i=1; i<n; i++)
//    {
//        m = ar[i]+ar[i-1];
//        if(m>x)
//        {
//            ll baki = m-x,f1,f2;
//             cnt += baki;
//
//            f1 = min(ar[i],baki);
//
//            ar[i] -= f1;
//            baki -= f1;
//
//            f1 = min(ar[i-1],baki);
//
//            ar[i-1] -= f1;
//
//
//
//        }
//    }
//
//    cout << cnt << endl;
}
