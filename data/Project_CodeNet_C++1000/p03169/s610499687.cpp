#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> 
#define ff first 
#define endl "\n"
#define ss second 
#define li list<int>
#define vi vector<int>
#define ll long long int
#define pii pair<int,int>
#define vii vector<pair<int,int> >
#define mp make_pair
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define custom  pair<int,pair<int,int> >
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds; 
#define mod 1000000007
double dp[301][301][301];
double solve(int x,int y,int z,int n){
    if(x<0 || y<0 || z<0){
        return 0;
    }
    if(x==0 && y==0 && z==0)
    return 0;
    if(dp[x][y][z]>-0.5){
        return dp[x][y][z];
    }
    double exp=n+x*solve(x-1,y,z,n)+y*solve(x+1,y-1,z,n)+z*solve(x,y+1,z-1,n);
    return dp[x][y][z]=exp/(x+y+z);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int one=0;int two=0;int three=0;
    int ex;
    for(int i=0;i<n;i++){
        cin>>ex;
        if(ex==1){
            one++;
        }
        else if(ex==2){
            two++;
        }
        else{
            three++;
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(9)<<solve(one,two,three,n);
    return 0;
}