#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v.begin(),v.end())
#define COUT(x) cout<<(x)<<'\n'

int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int count = 0;
    REP(i,3001){
        REP(j,3001){
            if(r*i+g*j>n)break;
            else if((n-r*i-g*j)%b==0)count++;
        }
    }
    COUT(count);
    return 0;
}