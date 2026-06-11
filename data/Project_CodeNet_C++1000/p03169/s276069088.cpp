//Author rahuliitkgp

/*A thing of beauty is a joy forever,
Its loveliness increases,
it will never pass into nothingness.*/
//Men at Work :)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;

#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define INF (int)1e9 + (int)1e8
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void cpp() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

double dp[301][301][301];

double solve(ll x, ll y, ll z, ll& n){
    if(x<0 || y<0 || z<0) return 0;
    if(x==0&&y==0&&z==0) return 0;
    if(dp[x][y][z]>-1.0) return dp[x][y][z];
    double exp = n+x*solve(x-1, y, z, n)+y*solve(x+1, y-1, z, n)+z*solve(x, y+1, z-1, n);
    return dp[x][y][z] = exp/(x+y+z);
}

int main(){
    cpp();
    memset(dp, -1, sizeof dp);
    ll n;
    cin>>n;
    ll one=0, two=0, three=0;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        if(x==1) one++;
        else if(x==2) two++;
        else three++;
    }
    cout<<ps(solve(one, two, three, n), 9)<<endl;
    return 0;
}




