    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace std;
    using namespace __gnu_pbds;
    typedef long long int ll;
    typedef unsigned long long lu;
    typedef long double ld;
    typedef pair<ll,ll> pr;
    typedef vector<ll> v;
    typedef vector<vector<ll> > vv;
    typedef vector<string>  vs;
    typedef vector<pair<ll,ll>> vp;
    #define in(x,n) for(ll i=0;i<n;i++)cin>>x[i]
    #define mp make_pair
    #define mt make_tuple
    #define ld long double
    #define f(i,n) for(ll i=0;i<n;i++)
    #define ff(i,n) for(ll i=1;i<=n;i++)
#define fr(i,n) for(ll i=n-1;i>=0;i--)
    #define  pb push_back
    #define aa(s) s.begin(),s.end()
    #define sz(x) (ll)x.size()
    #define fi first
#define ex exit(0)
//#define int long long
    #define se second
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

    #define mx(a) *(max_element(a.begin(),a.end()))
    #define mn(a) *(min_element(a.begin(),a.end()))

    // #define p 908197
    #define p  998244353
    #define mod 1000000007
 //   #define mod 998244353

    //#define mod  998244353
    //#define mod 1000000000
    #define  ti tuple
    //#define mod 998000099999
    #define sn struct node
    #define MAXN   200001
/*find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
*(s.find_by_order(2)) : 3rd element in the set i.e. 6
*(s.find_by_order(4)) : 5th element in the set i.e. 88


order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

 */

    const v dx = {1, -1, 0, 0};
    const v dy = {0, 0, 1, -1};
    const v dx1={0,1,-1,0,1,1,-1,-1};
    const v dy1={1,0,0,-1,1,-1,1,-1};
    const ld PI = 2 * acos(0.0);
    ll cel(ll x1,ll y1){if((x1%y1)==0)return x1/y1;else return x1/y1+1;}
    ll power(ll x, ll y)
    {
        ll res = 1;	 // Initialize result
        x=x%mod;
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x)%mod;

            // n must be even now
            y = y>>1; // y = y/2
            x = (x*x)%mod; // Change x to x^2
        }
        return res%mod;
    }
    ll power2(ll x, ll y)
    {
        ll res = 1;	 // Initialize result
        x=x;
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x);

            // n must be even now
            y = y>>1; // y = y/2
            x = (x*x); // Change x to x^2
        }
        return res;
    }
    ld power1(ld x, ll y)
    {
        ld res = 1;	 // Initialize result
        //x=x%mod;
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x);

            // n must be even now
            y = y>>1; // y = y/2
            x = (x*x); // Change x to x^2
        }
        return res;
    }
    void yes()
    {
        cout<<"YES\n";
    }
    void no()
    {
        cout<<"NO\n";
    }



    template<typename T> void print_queue(T& q) {
        while(!q.empty()) {
            std::cout << q.top() << " ";
            q.pop();
        }
        std::cout << '\n';
    }



    //ll dp[][w]={0};
    /*vector<pair<ll,pair<ll,ll>>>v;ll len;
       ll dp[37][100002];
      ll solve(ll n,ll x,ll y,ll z,ll p)
      {
        if(n==len)
        {
            return 1;
        }
        if(dp[p][n]!=-1)
        {
            return dp[p][n];



        }
        ll ans=0;

          return dp[p][n]=ans;


      }
      */
    /*
        vector<ll> merge(vector<ll> v1,vector<ll> v2)
        {
            vector<ll> x;
            ll i,j,k,l,m,n,o,p,q,r,s,t;
            m=v1.size();i=0;
            n=v2.size();j=0;
            while(i<m&&j<n)
            {
                if(v1[i]<v2[j])
                {
                    x.push_back(v1[i]);
                    i++;
                }
                else
                {
                    x.push_back(v2[j]);
                    j++;
                }
            }
            while(i<m)
            {
                x.push_back(v1[i]);
                i++;
            }
            while(j<n)
            {
                x.push_back(v2[j]);
                j++;
            }
            return x;
        }
        vector<ll>sa[1000000];
        ll a[1000000];
        void build(ll s,ll e,ll i)
        {
            if(s==e)
            {
                sa[i].push_back(a[s]);
                return;
            }
            ll m=(s+e)/2;
            build(s,m,2*i+1);
            build(m+1,e,2*i+2);
            sa[i]=merge(sa[2*i+1],sa[2*i+2]);
        }
        ll query(ll s,ll e,ll l,ll r,ll i,ll x1,ll x2)
        {
            if(e<l || r<s || s>e)
                return 0;
            if(s>=l && e<=r)
            {
                ll v1= upper_bound(sa[i].begin(),sa[i].end(),x1)-sa[i].begin();
               // ll v2= lower_bound(sa[i].begin(),sa[i].end(),x2-1)-sa[i].begin();
                return v1;
            }
            ll m=(s+e)/2;
            ll ls=query(s,m,l,r,2*i+1,x1,x2);
            ll rs=query(m+1,e,l,r,2*i+2,x1,x2);
            return ls+rs;
        }
    */







    // Returns n^(-1) mod p
    /*
    ll modInverse(ll n)
    {
        return power1(n, p-2);
    }

    // Returns nCr % p using Fermat's little
    // theorem.
    ll fac[500001];

    ll nCrModPFermat(ll n, ll r)
    {
        // Base case
        if (r==0)
            return 1;

        // Fill factorial array so that we
        // can find all factorial of r, n
        // and n-r


        return (fac[n]* modInverse(fac[r]) % p *
                modInverse(fac[n-r]) % p) % p;
    }
     */
    /*
    vector<vector<pair<ll,ll>>>a(100003);
    ll par[100003];ll size[100003];
    ll find(ll x)
    {
        while(par[x]!=x)
        {
            par[x]=par[par[x]];
            x=par[x];
        }
        return x;
    }
    void union1(ll x,ll y)
    {
        ll xroot=find(x);
        ll yroot=find(y);
        if(xroot==yroot)
            return;
        if(size[xroot]>=size[yroot])
        {
            par[yroot]=xroot;
            size[xroot]+=size[yroot];
        } else
        {   par[xroot]=yroot;
            size[yroot]+=size[xroot];}
    }
     */
    void gv(v a,ll  n)
    {
        f(i,n) {
            cin >> a[i];
    //cout<<a[i]<<" ";
        }
    //    cout<<"\n";
    }
    void out(v a,ll  n)
    {
        f(i,n)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    void sor(v &a,v &b,ll n)
    {
        vector<pair<ll,ll>>v;
        f(i,n)
        {
            // cout<<b[i]<<" "<<a[i]<<"\n";
            v.push_back(mp(a[i],b[i]));

        }
        sort(aa(v));
        f(i,n)
        {a[i]=v[i].first;b[i]=v[i].second;
        }
    }




    /*ll t;cin>>t;
    f(wq,t) {
    }
         */
    /*
    vector<vector<ll> > vec(row);
     vector<vector<ll> > vec( n , vector<ll> (m,0));
    for(auto i:m2)

     ordered_set s;

     bitset<44>a,b;           //44 bits initialized with 0
a[1]=1;
b[2]=1;
b=(b|a);
cout<<b<<"\n";      //order of binary  number
f(i,40)
{
   cout<<b[i];          //normal like array  (indexing starts from right that is least signifacnt bit
}

     */
//#define N 4
ll count(ll mask)
    {
    ll co=0;
    while(mask>0)
    {
        if(mask%2==1)
            co++;
        mask/=2;
    }
        return  co;
    }
    ll ffs1(ll mask)
    {
    ll co=0;
        while(mask>0)
        {
            if(mask%2==1)
            {
                return co;
            }
            mask/=2;
            co++;
        }

    }
    int main() {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

            ll n, m;
            cin >> n;
            ll arr[n][n];
            f(i,n)
            {
                f(j,n)
                {
                    cin>>arr[i][j];
                }
            }
ll n1=(1<<n);
           v dp(n1,0);
           dp[0]=1;
f(mask,n1)
{

    ll co=count(mask);
f(j,n) {
    if (arr[co][j] == 1&& !((1<<j)&mask))
    {
        dp[(1<<j)|mask]+=dp[mask];
        dp[(1<<j)|mask]%=mod;
    }

}

}
cout<<dp[n1-1]%mod<<"\n";

     //i//f(n>=3)
        return 0;
    }

