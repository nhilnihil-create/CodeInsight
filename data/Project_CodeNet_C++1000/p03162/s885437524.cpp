#include <iostream> 
#include <cstring> 
#include <climits>
using namespace std;

#define int long long int
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int> >
#define f first
#define s second
#define all(x) x.begin() , x.end()
#define mii map<int,int>
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define mk(arr,n,type) type *arr=new type[n]
#define w(x) int x;cin>>x;while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x
#define FOR(i,a,n) for(int i = a;i<n;i++)
#define FORD(i,a,n) for(int i = a;i<=n;i++)
#define FORR(i,n,a) for(int i = n;i>=a;i--)
#define endl "\n"

struct happiness {
    int a,b,c;
};

void solve(happiness *arr,int n) {
    
    int t1=arr[0].a,t2=arr[0].b,t3=arr[0].c;
    int x,y,z;
    FOR(i,1,n) {
        x = max(t2+arr[i].a,t3+arr[i].a);
        y = max(t1+arr[i].b,t3+arr[i].b);
        z = max(t1+arr[i].c,t2+arr[i].c);
        t1 = x,t2 = y,t3 = z;
    }
    cout<<max(t1,max(t2,t3))<<endl;
}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // w(x) {
        
        int n;
        cin >>n;
        happiness arr[n+10];
        FOR(i,0,n) {
            cin >>arr[i].a >>arr[i].b >>arr[i].c;
        }
        
        solve(arr,n);
        
    // }
}