#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<long long int>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vb vector<bool>
#define vvl vector<vector<ll> >
#define vvi vector<vector<int> >
#define pl pair<ll,ll>
#define pb push_back
#define PI 3.14159265
#define mod 998244353
#define pb push_back
#define mp make_pair
#define fri(s,n) for(int i=s;i<n;i++)
#define frj(s,n) for(int j=s;j<n;j++)
#define T(i) int i=1;cin>>i;while(i--)
#define vsi vector<set<int> >
#define pii pair<int,int>
#define inf 1e9
#define vpii vector<pair<int,int> >


ll power(ll a,ll b){
    if(b==0)
        return 1;
    if(b&1)
        return a*power(a,b-1);
    ll temp=power(a,b/2);
    return temp*temp;
    }
bool mycompare(ll a,ll b){
    return a>b;
    }
double dp[301][301][301];
double trials(int x,int y,int z,int n){
    if(x<0 || y<0 || z<0)
        return 0.0;
    if(x==0 && y==0 && z==0)
        return 0.0;
    //cout<<x<<" "<<y<<" "<<z<<"\n";
    if(dp[x][y][z]>-0.1)
        return dp[x][y][z];
    return dp[x][y][z]=(n+x*trials(x-1,y,z,n)+y*trials(x+1,y-1,z,n)+z*trials(x,y+1,z-1,n))/(x+y+z);
    }
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast;
    int n;
    cin>>n;
    int x=0,y=0,z=0;
    fri(0,n){
        int temp;
        cin>>temp;
        if(temp==1)
            x++;
        else if(temp==2)
            y++;
        else
            z++;
        }
    memset(dp,-1.0,sizeof dp);
    //vector<vector<vector<double> > > dp(x+1,vector<vector<double> >(y+1,vector<double>(z+1,-1.0)));
    cout<<setprecision(15)<<trials(x,y,z,n);


}
