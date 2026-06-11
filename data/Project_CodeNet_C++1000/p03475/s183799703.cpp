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
    vector<int> C(N),S(N),F(N);

    for (int i = 0; i < N-1; ++i) {
        cin>>C[i]>>S[i]>>F[i];
    }

    for (int i = 0; i < N; ++i) {
        int ans=0;
        for (int j = i; j < N-1; ++j) {
            if(ans<S[j]) ans=S[j]+C[j];
            else{
                ans=(ans-1+F[j])/F[j]*F[j]+C[j];
            }
        }
        cout<<ans<<endl;
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
