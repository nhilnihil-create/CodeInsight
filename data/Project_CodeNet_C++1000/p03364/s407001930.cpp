#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 10000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int n;
char s[600][600];
bool b[600][600];

signed main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    rep(i,n)rep(j,n){
        char c; cin>>c;
        s[i][j]=s[i+n][j]=s[i][j+n]=s[i+n][j+n]=c;
    }

    rep(i,n)rep(j,n){
        bool same=true;
        rep(k,n){
            if(s[i+k][j]!=s[i][j+k]){
                same=false; break;
            }
        }
        b[i][j]=b[i+n][j]=b[i][j+n]=b[i+n][j+n]=same;
    }

    int cnt=0;
    rep(i,n)rep(j,n){
        bool ok=true;
        rep(k,n){
            if(!b[i+k][j+k]){
                ok=false; break;
            }
        }
        if(ok)cnt++;
    }
    cout<<cnt<<endl;

}