#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
int main(){
    int n;cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vi AB(n),A(n),B(n);
    rep(i,n){
        int num=(int)s[i].size();
        s[i]+='#';
        rep(j,num){
            if(s[i][j]=='A'&&s[i][j+1]=='B'){
                AB[i]++;
                j++;
            }
            else if(j==num-1&&s[i][j]=='A'){
                A[i]++;
            }
            else if(j==0&&s[i][j]=='B'){
                B[i]++;
            }
        }
    }
    int ans=0;
    int BA=0,AA=0,BB=0;
    rep(i,n){
        ans+=AB[i];
        if(A[i]&&B[i]) BA++;
        else if(A[i]) AA++;
        else if(B[i]) BB++;
    }
    //cout << ans << endl;
    //cout << BA << " " << AA << " " << BB << endl;
    if(BA>0){
        ans+=BA-1+(AA>0)+(BB>0);
        if(AA>0) AA--;
        if(BB>0) BB--;
        ans+=min(AA,BB);
    }
    else{
        ans+=min(AA,BB);
    }
    cout << ans << endl;
    return 0;
}