#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
const char newl = '\n';
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL<<60;

int main(){
    int n;cin >> n;
    vector<P> x(n);
    rep(i,n) cin >> x[i].first >> x[i].second;
    vector<P> y(n);
    rep(i,n) cin >> y[i].first >> y[i].second;

    sort(ALL(x));
    sort(ALL(y));
    multiset<int> ms;
    int cur = 0;
    int ans = 0;
    rep(i,n){
        while(cur<n&&x[cur].first<y[i].first){
            ms.insert(x[cur].second);
            cur++;
        }
        auto it = ms.lower_bound(y[i].second);
        if(it!=ms.begin()){
            it--;
            ms.erase(it);
            ans++;
        }
    }
    cout << ans << endl;
}
