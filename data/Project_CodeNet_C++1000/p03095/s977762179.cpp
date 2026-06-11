    #include <bits/stdc++.h>
    using namespace std;
         
    #define fast { ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); }
    #define pb push_back
    #define ll long long
    #define ld long double
    #define vll vector<long long>
    #define infl LONG_LONG_MAX
    #define infd LDBL_MAX
    #define F first
    #define S second
    #define pll pair<ll,ll> 
    #define G(a,b) get<a>(b)
    #define ALL(v) v.begin(),v.end()
    #define MP make_pair
    #define MT make_tuple
    #define f(i,a,b) for(ll i=a;i<b;i++)
    #define fi(i,a,b) for(ll i=(b-1);i>=a;i--)    
    #define endl "\n"
    #define nl cout<<"\n";
    #define pr(x) cout<<x;
    #define pr1(x) cout<<x<<" ";
    #define pr2(x,y) cout<<x<<" "<<y;

    ll p=1e9+7;
      
    ll modpro(ll x,ll y,ll z=1)
    {
      x%=p;
      y%=p;
      z%=p;
      ll res=(x*y)%p;
      res=(res*z)%p;
      return res;
    }
     
    ll modadd(ll x,ll y,ll z=0)
    {
      x%=p;
      y%=p;
      z%=p;
      ll res=(x+y)%p;
      res=(res+z)%p;
      return res;
    }



    void func()
    {
       ll n;
       cin>>n;
       string s;
       cin>>s;
       ll cnt[26]={},ans=0;
       f(i,0,n)
       {
         ll temp=1;
         char ch='a';
         f(j,0,26)
         {
            if(ch!=s[i]) temp=modpro(temp,cnt[j]+1);
            ch++;
         }
         ans=modadd(ans,temp);
         cnt[s[i]-'a']++;
       }
       
       pr(ans) nl
    }     
     
     
    int main() 
    {
        fast
        //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //#endif // ONLINE_JUDGE
        
     
        ll ntc=1;
        //cin>>ntc;
     
        f(i,1,ntc+1)
        {
          //cout<<"Case #"<<i<<": ";
          func();
        }
     
        return 0;
    }