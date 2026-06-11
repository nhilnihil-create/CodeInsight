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
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }

    if(a[0]!=0){
        cout<<-1<<endl;
        return;
    }

    ll ans=0ll;
    int cnt=0;
    for (int i = 1; i < N; ++i) {
        if(a[i]>i||a[i]-a[i-1]>1){
            cout<<-1<<endl;
            return;
        }
        if(a[i]==0){
            ans+=cnt;
            cnt=0;
        }else if(a[i]-a[i-1]==1){
            cnt++;
        }else if(a[i]==a[i-1]){
            cnt++;
            ans+=a[i]-1;
        }else if(a[i]<a[i-1]){
            ans+=cnt;
            cnt=a[i];
        }
        //cout<<ans<<" "<<cnt<<endl;
    }
    ans+=cnt;
    cout<<ans<<endl;

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
