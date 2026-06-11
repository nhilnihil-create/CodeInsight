#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int max1=INF;
    for(int i=0;i<2*max(x,y)+1;i+=2){
            int ap = max(x-(i/2),0);
            int bp = max(y-(i/2),0);
            max1 = min(i*c+ap*a+bp*b,max1);
    }
    COUT(max1);
    return 0;
}