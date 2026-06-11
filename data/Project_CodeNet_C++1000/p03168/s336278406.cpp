    #include <bits/stdc++.h>
       
    using namespace std;
    #define ll long long
    #define ld long double
    #define pll pair<long long,long long>
    #define vll vector<long long>
    #define pb push_back
    #define mp make_pair
    #define ff first
    #define ss second
    #define deb(x) cout << #x << "=" << x << endl
    #define F(i,a,b) for(ll i=a;i<=b;i++)
    #define RF(i,a,b) for(ll i=a;i>=b;i--)
    #define in(a,n) F(i,0,n-1)cin>>a[i]
    #define vi vector<int>
    #define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<endl
    #define mod 1000000007
    #define trace1(x)                cerr<<#x<<": "<<x<<endl
    #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
    #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
    #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
    #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
    #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
    #define int long long
    const int N=(int)3e3+5,INF=(int)1e18+7;
    
    double dp[N][N];
    double p[N];
   
    void solve()
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>p[i];
        
        
        //dp[idx][head] tells probability 
        
        dp[0][0]=(1-p[0]);
        dp[0][1]=(p[0]);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=3000;j++)
            {
                //tail
                dp[i][j]+=(1-p[i])*dp[i-1][j];
                //head
                if(j-1>=0)
                dp[i][j]+=p[i]*dp[i-1][j-1];
                
            }
        }
        double ans=0;
        for(int i=n/2+1;i<=3000;i++)
        {
            ans+=(dp[n-1][i]);
        }
        
        cout<<fixed<<setprecision(10)<<ans;
    }
    
    int32_t main()
    {
    	ios::sync_with_stdio(false);
        cin.tie(NULL);
        
    	int t=1;
    	//cin>>t;
    	while(t--)solve();
    	    
       
    }
