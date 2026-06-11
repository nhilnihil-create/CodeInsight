#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
//const ll MOD=(ll)998244353;
const ll INF=(ll)1e18+10;
const double PI = 2.0*acos(0);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void solve(int ca){
    int N; cin>>N;
    vector<pair<int,int>> ans;
    if(N&1){
        for (int i = 1; i <= N-1; ++i) {
            for (int j = i+1; j <= N; ++j) {
               if(i+j==N) continue;
               ans.emplace_back(i,j);
            }
        }
    }else{
        for (int j = 1; j <= N-1 ; ++j) {
            for (int i = j+1; i <= N; ++i) {
                if(i+j==N+1) continue;
                ans.emplace_back(j,i);
            }

        }
    }
    cout<<ans.size()<<endl;
    for(auto path:ans){
        cout<<path.first<<" "<<path.second<<endl;
    }
}

//#define MULTI
int main() {
#ifdef MULTI
    int N; cin>>N;
    for (int i = 0; i < N; ++i) {
        solve(i+1);
    }
#else
    solve(0);
#endif
    return 0;
}
