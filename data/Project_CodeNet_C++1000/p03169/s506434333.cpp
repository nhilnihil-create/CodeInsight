
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
 
    using namespace std;
    using namespace __gnu_pbds;
 
    #define endl "\n"
    #define fi first
    #define se second
    #define pb push_back
    #define int long long
    #define ll long long
    #define ld long double
    #define pii pair<ll,ll>
 
    #define read(t) ll t;cin>>t;
    #define all(value) value.begin(),value.end()
    #define f(a,b,c) for(ll a=b;a<c;a++)
    #define For(i,n) for(ll i=0;i<n;i++)
 
    #define what(value) cerr << #value << " is " << value << endl;
    #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) ;
 
    typedef tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> omultiset;
    typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> oset;
    typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> oset1;
 
/*.....................................................................................................................*/
 
   
    //a.erase(unique(a.begin(),a.end()),a.end());
    double pi=3.141592653589793238462641;
    ll dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    const int mod=1e9+7 ,  inf =1e18;
    const ll  man =(int)305;
    

    long long binpow(int a,int b,int m)
    {   
        a %= m;int res = 1;
        while (b > 0)
        { 
            if (b & 1)res=(res*a)%m;
            a=(a*a)%m  ;    b/=2; 
        }
        return res;
    }
    int modinv(int n,int m) {return binpow(n,mod-2,m);}
    

/*......................................................................................................................*/

ld dp[man][man][man];
signed main()
{
    fast;
    int n;
    cin>>n;
    int A=0,B=0,C=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==1)A++;
        else if(x==2)B++;
        else C++;
    }
    for(int c=0;c<man;c++)
    {
        for(int b=0;b+c<man;b++)
        {
            for(int a=0;a+b+c<man;a++)
            {
                ld total=a+b+c;
                if(a==0&&b==0&&c==0)continue;
                ld aa=a/total;
                ld bb=b/total;
                ld cc=c/total;
                // ld xx =1-aa-bb-cc;
                dp[a][b][c]=n/total;
                if(a)dp[a][b][c]+=dp[a-1][b][c]*aa;
                if(b)dp[a][b][c]+=dp[a+1][b-1][c]*bb;
                if(c)dp[a][b][c]+=dp[a][b+1][c-1]*cc;
            }
        }
    }
    cout<<fixed<<setprecision(10)<<dp[A][B][C]<<endl;
}   

