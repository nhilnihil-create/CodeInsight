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
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int n,m;
    cin >> n >> m;
    int P[m],Y[m];
    REP(i,m){
        cin >> P[i] >> Y[i];
        P[i]--;
    }
    vector<vector<int>> v(n);
    REP(i,m)v[P[i]].push_back(Y[i]);
    REP(i,n)sort(v[i].begin(),v[i].end());
    REP(i,m){
        int it = lower_bound(v[P[i]].begin(),v[P[i]].end(),Y[i])-v[P[i]].begin();
        printf("%06d",P[i]+1);
        printf("%06d\n",it+1);
    }
    return 0;
}
