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
    string s;cin >> s;
    vi num;
    rep(i,(int)s.size()){
        if(s[i]=='A') num.push_back(0);
        else if(s[i]=='B') num.push_back(1);
        else num.push_back(2);
    }
    int n=(int)num.size();
    ll c=0;
    ll prec=0;
    bool pre=false;
    ll ans=0;
    int i=0;
    while(i<n-1){
        if(num[i]==0){
            c++;
            i++;
        }
        else{
            if(num[i]==1&&num[i+1]==2){
                if(pre){
                    ans+=prec+c;
                }
                else ans+=c;
                pre=true;
                prec=prec+c;
                c=0;
                i+=2;
            }
            else{
                pre=false;
                c=0;
                prec=0;
                i++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
