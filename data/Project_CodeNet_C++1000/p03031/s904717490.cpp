#include <bits/stdc++.h> 
    #include<ext/pb_ds/assoc_container.hpp> 
    #include<ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    using namespace std;
    template <typename T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    #define int long long  
    typedef long double ld;
    #define pb push_back
    #define f(i,a,b) for(int i=a;i<b;i++)
    #define fd(i,a,b) for(int i=a-1;i>=b;i--)
    #define pf push_front
    #define fi first
    #define se second
    #define ps(x,y)         fixed<<setprecision(y)<<x
    #define INF 1e10
    const double pi=3.14159265358979323;
    const int mod=998244353;
    const int MAX=1000000+5;
    int p[MAX]={0};

     int gcd(int a, int b) 
    { 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
    } 
    void swap(int a,int b)
    {
      int temp=a;
      a=b;
      b=temp;
    } 
    int  binpow(int  a,int  b) 
    {
    int res = 1;
    while (b > 0) {
        if (b%2 == 1)
            res = (res * a)%mod;
        a = (a* a)% mod;
        b >>= 1;
    }
    return res;
}
    int modinv(int y)
    {
        return binpow(y,mod-2);
    }

    int fact[500000+5];
    void precal()
    {
    fact[0]=1;
    for(int i=1;i<500000+5;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
    }
}
    bool isPrime(int n) 
    { 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
   
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
    } 
    int mm[200000+5];
    int vis[200000+5]={0};
    signed main() {

 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    #ifndef ONLINE_JUDGE
      if(fopen("INPUT.txt","r"))
      {
      freopen ("INPUT.txt" , "r" , stdin);
      freopen ("OUTPUT.txt" , "w" , stdout); 
      }
    #endif  
    // -------------------------------------Code starts here--------------------------------------------------------------------- 
    int t=1; 
   // cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int p[m];
        int k[m];
        int z[m][10];
        f(i,0,m)
        {
            cin>>k[i];
            f(j,0,k[i])
            {
                cin>>z[i][j];
                z[i][j]--;
            }
        }
        f(i,0,m)
        {
            cin>>p[i];
        }
        int ans=0;
        f(i,0,(1<<n))
        {
            bool flag=true;
            f(j,0,m)
            {
                int cnt=0;
                f(r,0,k[j])
                {
                    if((1<<z[j][r])&i)
                        cnt++;
                }
                if(cnt%2!=p[j]%2)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

