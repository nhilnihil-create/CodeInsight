#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define rep(i,a,b)    for(int i=a;i<b;i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>;
#define mi  map<int,int>
#define mii map<pii,int>
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define sz(x) (int)x.size()
#define all(v) (v).begin(), (v).end()
#define ret(x) return cout<<x,0;
#define rety return cout<<"YES",0;
#define retn return cout<<"NO",0;
#define fl fflush(stdout)   
#define hell 1000000007  
#define hell2 998244353 
#define pi 3.14159265358979323846

int solve(){
    int x,a,b,c,t=0;
    cin>>a>>b>>c>>x;
    rep(i,0,min(a+1,x/500+1)){
        int y=x-500*i;
        rep(j,0,min(b+1,y/100+1)){
            int z=y-100*j;
            if(z/50<=c)t++;//,cout<<i<<" "<<j;
          /*  rep(k,0,min(c,z/50+1)){
                t++;
                cout
            }*/
        }
    }
    cout<<t;
    return 0;
}

signed main(){
    auto start = high_resolution_clock::now();
    IOS;
    int t=1;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
   // cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr<<"Time taken:"<<duration.count()/1000000.0<<"seconds"<<"\n";
    return 0;
} 