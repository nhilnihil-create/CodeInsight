#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;
const double PI=acos(-1);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void solve() {
    int N; cin>>N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }

    ll maxi=2,mini=2;
    for (int i = N-1; i >= 0; --i) {
        ll b_maxi = maxi/a[i]*a[i];
        ll b_mini = ((mini-1)/a[i]+1)*a[i];
        if(b_maxi<mini){
            cout<<-1<<endl;
            return;
        }

        maxi=b_maxi+a[i]-1;
        mini=b_mini;

    }
    cout<<mini<<" "<<maxi<<endl;

}


#define SINGLE
int main() {
#ifdef SINGLE
    solve();
#else
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        solve();
    }
#endif
    return 0;
}
