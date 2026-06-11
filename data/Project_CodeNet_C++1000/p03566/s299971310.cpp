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
template<class T>bool chmax(T &a, const T &b) { if (a<=b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<=a) { a=b; return 1; } return 0; }
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    cout<<fixed<<setprecision(10);
    int n;
    cin>>n;
    vector<double> t(n+1),v(n+2);
    rep(i,n) cin>>t[i+1];
    rep(i,n) cin>>v[i+1];
    
    
    rep(i,n) {
        chmin(v[i+1],v[i+2]+t[i+1]);
        chmin(v[i+1],v[i]+t[i+1]);
    }
    rrep(i,n) {
        chmin(v[i+1],v[i+2]+t[i+1]);
        chmin(v[i+1],v[i]+t[i+1]);
    }

    double ans=0;
    FOR(i,1,n) {
        if(v[i-1]<=v[i] && v[i]<=v[i+1]) {
            ans+=v[i]*t[i]-pow((v[i]-v[i-1]),2)/2;
        }
        else if(v[i-1]>=v[i] && v[i]>=v[i+1]) {
            ans+=v[i]*t[i]-pow((v[i]-v[i+1]),2)/2;
        }
        else if(v[i-1]<v[i] && v[i]>v[i+1]) {
            double d=v[i+1]-v[i-1];
            ans+=t[i]*(v[i-1]+t[i]/2+d/2)-(pow(t[i]/2+d/2,2)+pow(t[i]/2-d/2,2))/2-pow(max(0.0,v[i-1]+t[i]/2+d/2-v[i]),2);
        }
        else {
            ans+=v[i]*t[i];
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
