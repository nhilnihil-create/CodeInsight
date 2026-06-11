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

vector<int> to[1000010], from[1000010];
int dp[1000010];
int taio[1000010];

void solve() {
    int N; cin>>N;
    vector<int> a(N),place(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
        place[a[i]-1] = i;
    }

    int longest=0;
    int left=0;
    for (int right = 1; right < N; ++right) {
        if(place[right]<place[right-1]){
            longest = max(longest,right-left);
            left=right;
        }
    }
    longest=max(longest,N-left);
    cout<<N-longest<<endl;
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
