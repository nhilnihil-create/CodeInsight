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
#define COUT(x) cout<<(x)<<endl

int main(){
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    REP(i,n){
        cin >> a[i];
        ans += a[i];
    }
    int min1 = INF,index=0;
    REP(i,n){
        if(min1>abs(a[i]*n-ans)){
            min1 = abs(a[i]*n-ans);
            index = i;
        }
    }
    COUT(index);
    return 0;
} 