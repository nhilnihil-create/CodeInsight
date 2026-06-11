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

void solve(int cn) {
    int N; cin>>N;
    vector<string> a(N);
    ll cnt[5]={0};
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
        switch(a[i][0]){
            case 'M':
                cnt[0]++;
                break;
            case 'A':
                cnt[1]++;
                break;
            case 'R':
                cnt[2]++;
                break;
            case 'C':
                cnt[3]++;
                break;
            case 'H':
                cnt[4]++;
        }
    }

    ll ans=0;
    for (int i = 0; i < 3; ++i) {
        for (int j = i+1; j < 4; ++j) {
            for (int k =j+1; k < 5; ++k) {
                ans += cnt[i]*cnt[j]*cnt[k];
            }
        }
    }
    cout<<ans<<endl;

}


#define SINGLE
int main() {
#ifdef SINGLE
    solve(1);
#else
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        solve(i);
    }
#endif
    return 0;
}
