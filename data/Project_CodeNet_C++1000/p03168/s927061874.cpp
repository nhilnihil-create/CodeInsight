#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

const int N=3001;
double dp[N];
vector<double> a(N);

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<=n;i++)
        dp[i]=0;
    dp[0]=1;
    for(ll i=0;i<n;i++){
        for(ll h=n+1;h>=0;h--){
            if(h==0) dp[h]=(1-a[i])*dp[h];
            else dp[h]=a[i]*dp[h-1]+(1-a[i])*dp[h];
        }
    }
    double ans=0;
    for(ll i=n/2+1;i<=n;i++)
        ans+=dp[i];
    cout<<fixed<<setprecision(10);
    cout<<ans;
    

    

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}