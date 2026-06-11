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
    int N,C; cin>>N>>C;
    vector<vector<bool>> used(C,vector<bool>(100010,false));
    int s,t,c;
    for (int i = 0; i < N; ++i) {
        cin>>s>>t>>c; --s; --c;
        for (int j = s; j < t; ++j) {
            used[c][j]=true;
        }
    }

    int ans=0;
    for (int i = 0; i <= 100000; ++i) {
        int cnt=0;
        for (int j = 0; j < C; ++j) {
            if(used[j][i]) cnt++;
        }
        //if(cnt==3) cout<<i<<endl;
        chmax(ans,cnt);
    }
    cout<<ans<<endl;

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
