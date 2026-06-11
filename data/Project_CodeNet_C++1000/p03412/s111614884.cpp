#include <bits/stdc++.h>
using namespace std;

using i64=int64_t;

#define rep(i,x,y) for(i64 i=i64(x),i##_max_for_repmacro=i64(y); i<i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif
 
const int inf=1.01e9;
const i64 inf64=4.01e18;
const double eps=1e-9;
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

void solve(){
    i64 N;
    cin >> N;

    vector<i64> a(N),b(N);
    rep(i,0,N) cin >> a[i];
    rep(i,0,N) cin >> b[i];

    vector<vector<i64>> sorted(29,vector<i64>(N));
    rep(i,0,29){
        sorted[i]=b;
        rep(j,0,N) sorted[i][j]%=1<<(i+1);
        i64 mask=1<<(i+1);
        sort(begin(sorted[i]),end(sorted[i]));
    }

    i64 ans=0;
    rep(k,0,29){
        i64 x=1<<k,s=0;
        rep(i,0,N){
            i64 a_=a[i]%(x*2);
            s+=lower_bound(begin(sorted[k]),end(sorted[k]),2*x-a_)-lower_bound(begin(sorted[k]),end(sorted[k]),x-a_);
            s+=lower_bound(begin(sorted[k]),end(sorted[k]),4*x-a_)-lower_bound(begin(sorted[k]),end(sorted[k]),3*x-a_);
        }
        ans|=(s%2)<<k;
    }

    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
