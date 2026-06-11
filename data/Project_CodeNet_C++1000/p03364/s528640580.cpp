#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<int,int> P;
typedef pair<ll,P> PP;
typedef vector<vector<int> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int main(){
    ll n;
    cin >> n;
    vector<string>st(n);
    rep(i,n)cin>>st[i];
    vector<string>yoko(n*2+1);
    vector<string>tate(n*2+1);
    rep(i,n){
        string now = st[i];
        now += st[i].substr(0,n-1);
        yoko[i]=now;
    }
    for(int i=n;i<2*n-1;i++){
        yoko[i]=yoko[i-n];
    }
    rep(i,n){
        string now = "";
        rep(j,n){
            now += st[j][i];
        }
        now += now.substr(0,n-1);
        tate[i]=now;
    }
    for(int i=n;i<2*n-1;i++){
        tate[i]=tate[i-n];
    }
    ll cnt = 0;
    rep(i,n){
        rep(j,n){
            bool flag = true;
            rep(k,n){
                if(tate[i+k].substr(j+k,n-k)!=yoko[j+k].substr(i+k,n-k))flag=false;
            }
            if(flag)cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

