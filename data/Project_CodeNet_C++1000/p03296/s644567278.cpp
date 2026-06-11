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
    REP(i,n){
        cin >> a[i];
    }
    int count = 1;
    int ans = 0;
    FOR(i,1,n){
        if(a[i]==a[i-1])count++;
        else {
            ans += count/2;
            count = 1;
        }
    }
    ans += count/2;
    COUT(ans);
    return 0;
} 

