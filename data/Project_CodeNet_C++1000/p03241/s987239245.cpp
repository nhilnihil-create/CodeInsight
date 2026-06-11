        #include<bits/stdc++.h>
        #include <ext/pb_ds/tree_policy.hpp> 
        #include <functional> // for less 
        using namespace __gnu_pbds; 
        using namespace std;
        //typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;    
        #define ll            long long
        #define pb            push_back
        #define ppb           pop_back
        #define si            set <ll>
        #define endl          '\n'
        #define fr            first
        #define sc            second
        #define mii           map<ll,ll>
        #define msi           map<string,ll>
        #define mis           map<ll,string>
        #define rep(i,a,b)    for(ll  i=a;i<b;i++)
        #define all(v)        v.begin(),v.end()
        #define sort(v)       sort(all(v))
        #define pii           pair<ll ,ll >
        #define vi            vector<ll >
        #define vii           vector<pair<ll,ll>>
        #define vs            vector<string>
        #define sz(x)         (ll)x.size()
        #define M             1000000007
        #define bs            binary_search
        #define rev(a)        reverse(all(a));
        #define sp(n)         setprecision(n)
        #define spl           " "
        #define arr(a,n)      rep(i,0,n) cin>>a[i]
        #define mod           998244353
        #define print_vector(a)  for(auto t:a) cout<<t<<" ";cout<<endl;
        #define print_arr(a,n)   rep(i,0,n) cout<<a[i]<<" "; cout<<endl;        
        #define show(a,n)     for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
        #define debug(x)      cout << #x << " is " << x << endl;
        #define time          cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
        #define INF           1ll<<31
        #define hi            cout<<"hi"<<endl;
        const ll maxn=int(3e5)+500;
        const ll maxa=(1<<20)+3;
        ll bpow(ll a, ll b, ll mm = M)
        {
            ll res = 1;
         
            while(b)
            {
                if(b & 1)
                    res = (res * a) % mm;
                a = (a * a) % mm;
         
                b >>= 1;
            }
         
            return res;
        }
        vector<ll> ret;
        vector<ll> getFactorization(ll n)
        {
            while (n % 2 == 0)  
            {  
                ret.pb(2);
                n = n/2;  
            }  

            for (ll i = 3; i <= sqrt(n); i = i + 2)  
            { 
                while (n % i == 0)  
                {  
                    ret.pb(i); 
                    n = n/i;  
                }  
            }  

            if (n > 2)  
               ret.pb(n);
            return ret;  
        }  
         
        ll modInverse(ll A,ll mm)
        {
        return bpow(A,mm-2,mm);
        }
        ll nCrModPFermat(ll n, ll r, ll p) 
        { 
         if (r==0) 
            return 1;
          ll fac[n+1]; 
          fac[0] = 1; 
          for (ll i=1 ; i<=n; i++) 
              fac[i] = fac[i-1]*i%p; 

          return (fac[n]*modInverse(fac[r],p)%p*modInverse(fac[n-r], p)%p)%p; 
        } 
         vector<ll> divisors(ll n)
        {
            vi res;
            for (ll i=1; i<=sqrt(n); i++)
            {
                if (n%i == 0)
                {
                    if (n/i == i)
                        res.pb(i);

                    else {
                        res.pb(i);
                        res.pb(n/i);
                    }
                }
            }
            return res;
        }
        const ll N=2e5+500;
        void solve()
        {
            ll n,m;
            cin>>n>>m;
            vi v=divisors(m);
            vi res;
            for(auto e:v)
                if(e<=m/n)
                res.pb(e);
            ll ans=0;
            for(auto e:res)
            {
                ll t=m-(n-1)*e;
                if(t>=1 && t%e==0) ans=max(ans,e);
            }
            cout<<ans;
        } 
        signed main()   
        {
            ios_base::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);
            #ifndef ONLINE_JUDGE
           // freopen("input.txt","r",stdin);
            //freopen("output.txt","w",stdout);
            #endif
            ll t=1;
            //cin>>t;
            while(t--) solve();
        }
