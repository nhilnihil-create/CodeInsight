#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
#define get_unique(x) x.erase(std::unique(all(x)), x.end());
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=acos(-1);
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int k;
    cin>>k;
    vector<ll> a(k);
    rep(i,k) cin>>a[i];
    vector<pair<ll,ll>> kids(k+1);
    kids[k]={2,2};
    
    if(a[k-1]!=2) {
        cout<<-1<<endl;
        return 0;
    }
    
    rrep(i,k) {
        ll L=kids[i+1].first,R=kids[i+1].second+a[i]-1;
        kids[i].first=(i==0 ? L : (((L-1)/a[i-1])+1)*a[i-1]);
        kids[i].second=(i==0 ? R : (R/a[i-1])*a[i-1]);
        if(!(L<=kids[i].first && kids[i].first<=R)) {
            cout<<-1<<endl;
            return 0;
        }
        if(!(L<=kids[i].second && kids[i].second<=R)) {
            cout<<-1<<endl;
            return 0;
        }
        //cout<<kids[i].first<<" "<<kids[i].second<<endl;
    }
    
    cout<<kids[0].first<<" "<<kids[0].second<<endl;
}
