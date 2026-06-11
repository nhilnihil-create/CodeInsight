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
    int n;cin >> n;
    vector<int> c(n-1),s(n-1),f(n-1);
    REP(i,n-1){
        cin >> c[i] >> s[i] >> f[i]; 
    }
    REP(i,n){
        ll ans = 0;
        FOR(j,i,n-1){
            if(ans<s[j])ans=s[j];
            if((ans-s[j])%f[j]!=0){
                ans += f[j]-(ans-s[j])%f[j];
            }
            ans += c[j];
        }
        COUT(ans);
    }
    return 0;
}