#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, h;cin>>n>>h;
    const int NM = 1e5+1;
    vector<int> a(n), b(n);
    int amx = 0;
    rep(i,n){
        cin>>a[i]>>b[i];
        chmax(amx, a[i]);
    }
    sort(all(b));
    // amx以上を投げる
    int ans = 0;
    while(!b.empty()){
        int t = b.back(); b.pop_back();
        if(t<amx) break;
        h-=t; ans++;
        if(h<=0)break;
    }
    if(h>0) ans+=(h+(amx-1))/amx;
    cout<<ans<<endl;
}