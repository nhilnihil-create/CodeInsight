#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) (v).begin(),(v).end()
#define COUT(x) cout<<(x)<<"\n"



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> vec(n+2,0);
    REP(i,n)cin >> vec[i+1];
    
    ll ans = 0;
    for(int i=0;i<n+1;i++){
        ans += abs(vec[i+1]-vec[i]);
    }
    for(int i=1;i<n+1;i++){
        COUT(ans+abs(vec[i+1]-vec[i-1])-abs(vec[i]-vec[i-1])-abs(vec[i+1]-vec[i])); 
    }
    return 0;
}