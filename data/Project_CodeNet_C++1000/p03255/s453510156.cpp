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
const i64 inf64=9.01e18;
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
    i64 N,X;
    cin >> N >> X;
    vector<i64> x(N);
    rep(i,0,N) cin >> x[i];

    vector<i64> s(N);
    s[0]=x[0];
    rep(i,1,N) s[i]=s[i-1]+x[i];

    auto sum=[&](int i, int j){
        i64 res=s[j];
        if(i) res-=s[i-1];
        return res;
    };

    i64 ans=numeric_limits<i64>::max();
    rep(i,1,N+1){
        i64 tmp=5*sum(N-i,N-1)+i*X,d=5;
        for(int j=N-i-1; j>=0; j-=i){
            tmp+=d*sum(max(j-i+1,i64(0)),j);
            d+=2;
            if(tmp>=ans) break;
        }
        ans=min(ans,tmp);
    }

    ans+=N*X;
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
