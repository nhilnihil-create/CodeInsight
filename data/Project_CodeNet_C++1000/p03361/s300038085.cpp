#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    vector<vector<bool>> f(h,vector<bool>(w,true));
    rep(i,h) cin>>s[i];
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    rep(i,h) {
        rep(j,w) {
            if (s[i][j]!='#') continue;
            rep(dir,4) {
                int nh=i+dy[dir];
                int nw=j+dx[dir];
                if (nh<0||nh>=h||nw<0||nw>=w) continue;
                if (s[nh][nw]=='#') {
                    f[i][j]=false;
                    f[nh][nw]=false;
                }
            }
        }
    }
    rep(i,h) {
        rep(j,w) {
            if (s[i][j]=='#'&&f[i][j]) {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}

