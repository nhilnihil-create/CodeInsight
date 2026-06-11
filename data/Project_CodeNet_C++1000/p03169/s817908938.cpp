#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
#define test ll t; cin>>t; while(t--)
typedef long long int ll;
ll n;
double dp[301][301][301];
bool vis[301][301][301];
double count(int x,int y,int z){
    if(vis[x][y][z]){
        return dp[x][y][z];
    }
    vis[x][y][z]=true;
    if(x+y+z==0){
        return dp[x][y][z]=0;
    }
    int total=x+y+z;
    double ans=double(n-total)/double(total);
    if(x>0){
        ans+=(double(x)/double(total)*count(x-1,y,z));
    }
    if(y>0){
        ans+=(double(y)/double(total)*count(x+1,y-1,z));
    }
    if(z>0){
        ans+=(double(z)/double(total)*count(x,y+1,z-1));
    }
    ans+=1;
    return dp[x][y][z]=ans;
}
int main() {
    FIO;
    //test
    {
        cin>>n;
        vector<ll>a(4,0);
        for(int i=0;i<n;i++){
            cin>>a[0];
            a[a[0]]++;
        }
        memset(vis,false,sizeof(vis));
        cout<<fixed<<setprecision(10)<<count(a[1],a[2],a[3])<<endl;
    }
	return 0;
}
