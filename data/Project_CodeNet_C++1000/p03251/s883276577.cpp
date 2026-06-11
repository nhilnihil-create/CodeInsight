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
    int n,m,x,y;cin>>n>>m>>x>>y;
    int xm=-1000000, ym=100000;
    rep(i, n){
        int t; cin>>t;
        xm = max(xm, t);
    }
    rep(i, m){
        int t; cin>>t;
        ym = min(ym, t);
    }
    string ans = "War";
    for(int i=xm+1; i<=ym; i++){
        if(x<i && i<=y){
            ans = "No War";
            break;
        }
    }

    cout << ans<< endl;
}