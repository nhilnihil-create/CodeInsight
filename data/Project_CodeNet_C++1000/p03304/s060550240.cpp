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
int main() {
    double n,m,d;
    cin>>n>>m>>d;
    double zero=max((double)0,d-(n-d));
    double two=max((double)0,(n-d)-d);
    double one=n-zero-two;
    cout<<fixed<<setprecision(10);
    //cout<<zero<<" "<<one<<" "<<two<<endl;
    if(d==0) cout<<(m-1)*two/(n*n)<<endl;
    else cout<<(m-1)*(one+two+two)/(n*n)<<endl;
}
