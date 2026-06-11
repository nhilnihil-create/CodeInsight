#include<bits/stdc++.h>9
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo 1e18
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define Matrix vector< vector < long long > >
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vs vector<string>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

const long double Pi=acos(-1),e=2.718,ebs=0.00000000001;
const int N=1e5+10,mod=1e9+7,SEED = 1331,B=40;
long double n;
vll a;
vector<vector<vector<long double> > > dp;

long double solve(int i,int j,int k){
    if(i==0 && j==0 && k==0)return 0;
    long double &ret=dp[i][j][k];
    if(ret+1)return ret;
    ret = 1;
    if(i)ret += solve(i-1,j,k)*i/(n);
    if(j)ret += solve(i+1,j-1,k)*j/(n);
    if(k)ret += solve(i,j+1,k-1)*k/(n);
    ret *= n/(i+j+k);
    return ret;
}

int main ()
{
    FASTIO
    cin >> n;
    a.assign(n,0);
    vll cnt(4,0);
    for(auto &x:a){
        cin >> x;
        cnt[x]++;
    }
    dp.assign(n+1,vector<vector<long double> >(n+1,vector<long double>(n+1,-1.0)));
    cout << fixed << setprecision(12) << solve(cnt[1],cnt[2],cnt[3]) << endl;

    return 0;

}
/**

*/
