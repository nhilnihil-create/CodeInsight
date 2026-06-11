#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
int solve(int x){
    int res=1;
    while(res<=x){
        res*=2;
    }
    return res-x;
}
signed main() {
    int N;cin>>N;
    vector<int>A(N);
    map<int,int>M;
    rep(i,N){
        cin>>A[i];
        M[A[i]]++;
    }
    sort(all(A),greater<int>());
    int ans=0;
    for(auto x:A){
        if(M[x]==0)continue;
        M[x]--;
        int next=solve(x);
        if(M[next]>0){
            M[next]--;
            ans++;
        }
    }
    cout<<ans<<endl;
    
}
