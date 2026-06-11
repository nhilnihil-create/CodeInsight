#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(int i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    vector<bool>v1(100001, false),v2(100001, false);
    vector<int>v2cnt(100001);
    rep(i, 2, 100001){
        int cnt = 0;
        sqrep(j, 1, i){
            if(i%j==0){
                cnt++;
                if(j*j!=i)cnt++;
            }
        }
        if(cnt==2)v1[i]=true;
        if(v1[i]&&v1[(i+1)/2])v2[i]=true;
    }
    int p = 0;
    rep(i, 0, 100001){
        if(v2[i])p++;
        v2cnt[i] = p;
    }
    int q;
    cin >> q;
    vector<int>ans(q);
    rep(i, 0, q){
        int l, r;
        cin >> l >> r;
        ans[i]=v2cnt[r]-v2cnt[l-1];
    }
    rep(i, 0, q)cout << ans[i] << endl;
}