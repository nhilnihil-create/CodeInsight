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
    int N;
    cin >> N;

    int k=1;
    while(k*(k-1)/2<=N){
        if(k*(k-1)/2==N){
            break;
        }
        ++k;
    }

    if(k*(k-1)/2!=N){
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    vector<pair<int,int>> x(N);
    int j=0;
    rep(i,0,k){
        rep(l,i+1,k){
            x[j]=make_pair(i,l);
            ++j;
        }
    }

    cout << k << endl;

    vector<vector<int>> ans(k);
    rep(i,0,N){
        ans[x[i].first].push_back(i+1);
        ans[x[i].second].push_back(i+1);
    }

    rep(i,0,k){
        cout << ans[i].size();
        for(int j:ans[i]){
            cout << " "<< j;
        }
        cout << endl;
    }
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
