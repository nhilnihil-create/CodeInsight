#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {

    ll N,M;
    cin >> N >> M ;
    ll s[10][10];
    ll k[10];
    ll p[10];
    rep(i,M){
        cin >> k[i];
        rep(j,k[i]){
            cin >> s[i][j];
        }
    }
    rep(i,M){
        cin >> p[i];
    }

    int ans=0;
    for(int bit=0;bit<(1<<N);bit++){
        int res=0;
        for(int i=0;i<M;i++){
            int cnt=0;
            for(int j=0;j<k[i];j++){
                if(bit&(1<<s[i][j]-1)){
                    cnt++;
                }
            }
            if(cnt%2==p[i]){
                res++;
            }
        }
        if(res==M){
            ans++;
        }
    }
    cout << ans << endl;
}