#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
const LL LLINF = 1e16;

int main(){
    int n, k;
    cin >>n >> k;
    vector<pair<LL, LL>> a(n);
    rep(i, n) cin >> a[i].first >> a[i].second;

    sort(
        all(a),
        [](const pair<LL,LL>& x, pair<LL,LL>&y){
            if(x.first != y.first) return x.first<y.first;
            return x.second>y.second;
        }
    );

    vector<LL> v1, v2;
    int tmp = 0;
    repe(i, a){
        if(tmp != i.first){
            tmp = i.first;
            v1.push_back(i.second);
        }else{
            v2.push_back(i.second);
        }
    }
    sort(all(v1));
    sort(all(v2));
    v1.push_back(0);
    v2.push_back(0);
    reverse(all(v1));
    reverse(all(v2));
    rep(i, v1.size()-1) v1[i+1] += v1[i];
    rep(i, v2.size()-1) v2[i+1] += v2[i];

    LL ans = 0;
    rep1(i, k+1){
        LL x = min((int)v1.size(), i);
        int rem = k-x;
        if(rem >= v2.size()) continue;
        LL tmp = v1[x] + v2[k-x] + x*x;
        chmax(ans, tmp);
    }
    cout << ans <<endl;


}