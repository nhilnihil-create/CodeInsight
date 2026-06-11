#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>
inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll h,w;cin>>h>>w;
    vector<vector<char>> s(h,vector<char>(w));
    rep(i,h)rep(j,w) cin>>s[i][j];

    ll dx[4]={0,0,-1,1};
    ll dy[4]={1,-1,0,0};

    bool cant=false;
    rep(i,h){
        rep(j,w){
            bool allwhite=true;
            if(s[i][j]!='#') continue;
            rep(k,4){
                ll ny=i+dy[k],nx=j+dx[k];
                if(!(0<=ny && ny<h && 0<=nx && nx<w)) continue;
                if(s[ny][nx]!='#') continue;
                
                allwhite=false;
            }

            if(allwhite) cant=true;
        }
    }

    if(cant) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}