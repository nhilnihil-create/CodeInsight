
    #include <bits/stdc++.h>
    using namespace std ; 
    #define ll              long long int
    // #define cini(x)	        scanf("%lld",&x)
    // #define cins(s)	        scanf("%s",s)
    #define deb(x)          cout << (x) << "  " ;
    #define out(x)          cout << (x) << endl ;
    #define endl            '\n'
    #define pb              push_back
    #define mk              make_pair
    #define fastio          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #define loop(x,n,v)     for(ll v=x; v<n; v++)
    #define loopr(n,x,v)     for(ll v=n-1; v>=x; v--)
    #define mod             1000000007
    #define all(x)          x.begin(), x.end()
    #define clr(x)          memset(x, 0, sizeof(x))
    #define sortall(x)      sort(all(x))
    #define tr(it, a)       for(auto it = a.begin(); it != a.end(); it++)
    #define PI              3.1415926535897932384626
    #define setbits(x)      __builtin_popcount(x)
    #define zrobits(x)      __builtin_ctz(x)
    #define ps(x,y)         fixed << setprecision(y) << (x)
    #define w(t)            int t; cin>>t; while(t--) 
    #define     vi          vector<ll>
    #define     vtt         vector<pair<ll,ll>> 
    #define     pii         pair<ll,ll> 
    #define  mapp           map<ll,ll> 
    #define  sett           set<ll>
    // int dp[1000][1000] ;
    ll mpow(ll base, ll exp); 
    // =================================
    // =================================
ll arr[200002], brr[200002], maxi=-1; 
ll BIT[200002]={0};
ll a[200002];

void solve(ll i, ll mini, ll sum){
    maxi = max(maxi,sum);
    // cout << sum << " ";
    if(i < 0) return ;
    if(mini > arr[i]){
        solve(i-1,arr[i],sum+brr[i]);
        // solve(i-1,mini,sum);
    }
    solve(i-1,mini,sum);
}

void update(ll i, ll inc, ll N){
    // cout << " c " ;
    ll a=i ;
    while(i <= N){
        BIT[i] = max(inc,BIT[i]) ;
        // cout << BIT[i] << " " ; 
        i += (i&(-i));              //    Three steps
    }                               //   1.2`s complement of no
    // cout << BIT[a] << " " ;         //   2.And it with original no        
}                                   //   3.Add from original no

ll query(ll i){
    ll ans=0;
    while(i > 0){                   //    Three steps
        ans = max(BIT[i],ans);              //   1.2`s complement of no
        i -= (i&(-i));              //   2.And it with original no        
    }                               //   3.Substract from original no
    return ans ;
}


//  This is a binary index tree question (BIT).

int main(){
    fastio ;
    // w(t)
    // {
        ll a=0, b=0, c=0, d=0, e=0, p=0, q=0, r=0 ;
        ll ans=0, res=0, cnt=0, sum=0, diff=0, mul=1, val=0, k=0 ;
        // loop(0,n,i) brr[i]=0;
        // char s[100005];
        string s ;
        ll n,m ;
        cin >> n ;
        loop(1,n+1,i) cin >> arr[i] ;
        loop(1,n+1,i) cin >> brr[i] ;
        sett set ;
        for(int i=1; i<=n; i++){
            ll pref = query(arr[i]-1);      // suppose for arr[i]=4; if any element less than
                                            // 4 is present then max val will be present
                                            // at idx=3(law of BIT).
    		update(arr[i],pref+brr[i],n);   // Now we will update total sum BIT[arr[i]-1]+BIT[arr[i]]
	    	ans = max(pref+brr[i],ans);     // calculating max at each go
        }
       // loop(1,n+1,i)   cout << BIT[i] <<" " ;
        cout <<ans << endl ;

    return 0 ;
}
// g++ x.cpp -o as && ./as