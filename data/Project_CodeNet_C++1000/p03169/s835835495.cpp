#include <bits/stdc++.h>
#define db(x) cout<<x<<" "
#define db1(x) cout<<x<<'\n'
#define db2(x,y) cout<<x<<" "<<y<<'\n'
#define db3(x,y,z) cout<<x<<" "<<y<<" "<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define pair(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ll  long long int
#define vi vector<ll>
#define pi pair<ll,ll>
#define vpi vector<pair<ll,ll>>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define mod 1000000007
#define MAX_N 100000
using namespace std;
// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};
double dp[301][300][301];

double get(ll x, ll y, ll z, ll n){

    if(x<0||y<0||z<0)
        return 0;

    if(x==0&&y==0&&z==0)
        return 0;

    //db(x),db(y),db1(z);

    if(dp[x][y][z]>0.9)
        return dp[x][y][z];

    double exp = n+x*get(x-1,y,z,n)+y*get(x+1,y-1,z,n)+z*get(x,y+1,z-1,n);
    return dp[x][y][z] = exp/(x+y+z);
}

void solve(){

    ll n;
    cin>>n;
    memset(dp,-0.9,sizeof(dp));
    ll arr[n];
    ll x=0,y=0,z=0;
    rep(i,n){
        cin>>arr[i];
        if(arr[i]==1)
            x++;
        else if(arr[i]==2)
            y++;
        else
            z++;
    }
   
    double ans = get(x,y,z,n);

    cout<<fixed<<setprecision(10)<<ans<<endl;

}
int main(){ 

int t=1;
//cin>>t;
while(t--){
 solve();
}
  return 0; 
}



