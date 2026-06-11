#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<ll,ll> P;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define IINF 1e9

bool cmp(P a,P b){
    return a.second < b.second;
}
/* 
    memo:区間スケジューリング問題
*/
int main(void){
    ll m,n,ans = 0,end = 0;
    cin >> n >> m;
    vector<P> l(m);
    REP(i,m) cin >> l[i].first >> l[i].second;
    sort(l.begin(),l.end(),cmp);    // secondを基準に，昇順にソート
    REP(i,m){
        if(l[i].first >= end){
            end = l[i].second;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}