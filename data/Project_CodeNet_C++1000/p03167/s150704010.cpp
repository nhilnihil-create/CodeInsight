#include<bits/stdc++.h>

#define ll  long long int
#define ld  long double
#define MAX 1000001
#define MOD 1000000007
#define pi  3.14159265358979323846264338
#define mp  make_pair
#define pb  push_back
#define pll pair<ll,ll>
#define vl  vector<ll>
#define vi  vector<int>
#define vs  vector<string>
#define vc  vector<char>
#define fst first
#define sec second
#define foi(i, a, b)   for(ll i = a; i<b;i++)
#define fod(i, a, b)   for(ll i = a;i>=b;i--)
#define all(v)         (v).begin(), (v).end()
#define max3(a, b, c)  max(max(a,b), c)
#define min3(a, b, c)  min(min(a,b), c)
#define ump  unordered_map<ll,ll>
#define us   unordered_set<ll>
#define nl  "\n"
#define INF  (ll)1e18
#define s(v) (ll)(v).size()
#define e(v) (v).empty

using namespace std;

ll gcd(ll a,ll b) { if (a==0) return b; return gcd(b%a,a);}


void solve(){
    ll h,w;
    cin>>h>>w;

    vector<vector<ll>> a(h,vector<ll>(w));

    char c;
    foi(i,0,h){
        foi(j,0,w){
            cin>>c;
            if(c=='.'){
                a[i][j] = 1;
            }else{
                a[i][j] = 0;
            }
        }
    }
    
    foi(i,0,w){
        if(a[0][i]==0){
            while(i<w){
                a[0][i] = 0;
                i++;
            }
        }
    }

    foi(i,0,h){
        if(a[i][0]==0){
            while(i<h){
                a[i][0] = 0;
                i++;
            }
        }
    }

    foi(i,1,h){
        foi(j,1,w){
            if(a[i][j]==0){
                continue;
            }else{
                a[i][j] = (a[i-1][j] + a[i][j-1])%MOD;
            }
            
        }
    }

    cout<<a[h-1][w-1]<<"\n";
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}