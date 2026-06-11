#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
const int nmax=301;
bool mem[nmax][nmax][nmax];
double dp[nmax][nmax][nmax];
int n;
double f(int x,int y,int z){
    if(!x&&!y&&!z){
        return 0;
    }
    if(mem[x][y][z]){
        return dp[x][y][z];
    }
    double res=(double)n/(x+y+z);
    if(x){
        res+=f(x-1,y,z)*(double)x/(x+y+z);
    }
    if(y){
        res+=f(x+1,y-1,z)*(double)y/(x+y+z);
    }
    if(z){
        res+=f(x,y+1,z-1)*(double)z/(x+y+z);
    }
    mem[x][y][z]=true;
    return dp[x][y][z]=res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> a(n);
    int x=0,y=0,z=0;
    REP(i,n){
        cin >> a[i];
        if(a[i]==1){
            x++;
        }
        if(a[i]==2){
            y++;
        }
        if(a[i]==3){
            z++;
        }
    }
    cout << fixed << setprecision(15) << f(x,y,z) << endl;
}