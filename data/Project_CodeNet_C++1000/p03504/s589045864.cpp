#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int n,c;
int ch[35][100010];
int main(){
    cin >> n >> c;
    rep(i,35){
        rep(j,100010){
            ch[i][j]=0;
        }
    }
    rep(i,n){
        int s,t,c;
        cin >> s >> t >> c;
        s--;t--;c--;
        ch[c][s]++;
        ch[c][t+1]--;
    }
    rep(i,35){
        rep(j,100005){
            ch[i][j+1]+=ch[i][j];
        }
    }
    int ans = 0;
    rep(i,100001){
        int tmp = 0;
        rep(j,35){
            if(ch[j][i])tmp++;
        }
        chmax(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}
