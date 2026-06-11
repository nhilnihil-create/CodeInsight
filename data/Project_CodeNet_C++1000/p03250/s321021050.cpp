#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    // int a,b,c; cin>>a>>b>>c;
    vector<int> a;
    rep(i, 3){
        int t; cin>>t;
        a.push_back(t);
    }
    int ans = 0;
    rep(i,3){
        rep(j,3){
            if(i==j) continue;
            int k = 3-i-j;
            ans = max(a[i]*10+a[j]+a[k], ans);
        }
    }
    cout << ans<< endl;
}