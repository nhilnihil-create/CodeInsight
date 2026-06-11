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
    string s;
    cin >> s;

    int N=s.size();

    vector<int> a(N+1);
    rep(i,1,N+1) a[i]=a[i-1]^(1<<(s[i-1]-'a'));

    vector<int> opt(N+1);
    static int dp[1<<26];
    fill_n((int*)dp,1<<26,inf);
    opt[0]=0;
    rep(i,1,N+1){
        if(a[i]==0) opt[i]=1;
        else opt[i]=dp[a[i]]+1;
        rep(j,0,26){
            opt[i]=min(opt[i],dp[a[i]^(1<<j)]+1);
            if(a[i]==(1<<j)) opt[i]=1;
        }
        dp[a[i]]=min(dp[a[i]],opt[i]);
    }

    cout << opt[N] << endl;
}
 
int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}