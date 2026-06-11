#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=3.14159265358979323846;
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

ll gcd (ll x,ll y) {
    if (x < y) swap(x, y);
    if (y == 0) return x;
    return gcd(x % y, y);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a<b || d<b) {
            cout<<"No"<<endl;
            continue;
        }
        if(c>=b) {
            cout<<"Yes"<<endl;
            continue;
        }
        
        ll g=gcd(b,d);
        if((((b-a%g)+g-1)/g)*g+a%g-g > c) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}
