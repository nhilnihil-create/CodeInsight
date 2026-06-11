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
    i64 N,C;
    cin >> N >> C;

    vector<i64> x(N),v(N);
    rep(i,0,N) cin >> x[i] >> v[i];

    i64 ans=0;
    vector<i64> a(N),b(N),s(N),t(N);
    {
        i64 tmp=v[0]-x[0];
        a[0]=s[0]=tmp;
        ans=max(ans,tmp);
        rep(i,1,N){
            tmp-=x[i]-x[i-1];
            tmp+=v[i];
            a[i]=tmp;
            s[i]=max(s[i-1],tmp);
            ans=max(ans,tmp);
        }
    }
    {
        i64 tmp=v[N-1]-(C-x[N-1]);
        b[N-1]=t[N-1]=tmp;
        ans=max(ans,tmp);
        for(int i=N-2; i>=0; --i){
            tmp-=x[i+1]-x[i];
            tmp+=v[i];
            b[i]=tmp;
            t[i]=max(t[i+1],tmp);
            ans=max(ans,tmp);
        }
    }

    rep(i,0,N-1) ans=max(ans,a[i]-x[i]+t[i+1]);
    rep(i,1,N) ans=max(ans,b[i]-(C-x[i])+s[i-1]);

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
