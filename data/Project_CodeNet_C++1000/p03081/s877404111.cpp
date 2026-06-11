#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int n,q;
string s;
vector<char> t,d;

bool f(int x,bool left){ //初期位置s[x]のゴーレムが生き残るならtrue
    int now=x;
    rep(i,q){
        if(t[i]!=s[now]) continue;
        now+=(d[i]=='L' ? -1 : 1);
        if(now<0){
            if(left) return false;
            else return true;
        }
        if(now>=n){
            if(left) return true;
            else return false;
        }
    }
    return true;
}

int main(){
    cin>>n>>q>>s;
    t.resize(q);
    d.resize(q);
    rep(i,q) cin>>t[i]>>d[i];
    
    int ng_left = -1, ok_left = n;
    while (ok_left - ng_left > 1) {
        int mid = (ng_left + ok_left) / 2;
        (f(mid,true) ? ok_left : ng_left) = mid;
    }
    if(ok_left==n) {
        cout<<0<<endl;
        return 0;
    }
    
    int ng_right = n, ok_right = -1;
    while (ng_right - ok_right > 1) {
        int mid = (ng_right + ok_right) / 2;
        (f(mid,false) ? ok_right : ng_right) = mid;
    }
    if(ok_right==-1) {
        cout<<0<<endl;
        return 0;
    }
    
    cout<<max(0,ok_right-ok_left+1)<<endl;
    
}
