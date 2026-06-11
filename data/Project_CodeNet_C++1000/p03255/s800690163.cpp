#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<unsigned long long> vull;
typedef unsigned long long ull;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define ULLINF 1e19
vint y;
vull sum;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vint y(n,0);
    vull sum(n+1,0);
    REP(i,n) {
        cin >> y[i];
        sum[i+1] = sum[i]+(ull)y[i];
    }
    ull ans = (ull)n*(ull)x;
    ull cost = ULLINF-1;
    for(int k=1;k<=n;k++){
        ull tmp = (ull)k*(ull)x;
        tmp+=5*(sum[n]-sum[n-k]);
        int f = n-k;
        ull c = 5;
        while(f>=0){
            if(f-k<0){
                tmp+=(sum[f]-sum[0])*c;
            }else{
                tmp+=(sum[f]-sum[f-k])*c;
            }
            c+=2;
            f-=k;
        }
        cost = min(cost,tmp);
    }
    ans+=cost;
    cout << ans << endl;
    return 0;
}