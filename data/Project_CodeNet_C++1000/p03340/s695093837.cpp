#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pi=pair<int,int>;
using vi=vc<int>;
void yes(){ cout << "Yes" << endl; }
void no(){ cout << "No" << endl; }
int SIZE(string s){ return (int)s.size(); }

int main(){
    cout << fixed << setprecision(20);
    int n; cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    int r = 0;
    ll sum = 0;
    ll ans = 0;
    rep(l,n){
        while(r < n && (sum ^ a[r]) == (sum + a[r])){
            sum += a[r];
            r++;
        }
        ans += r-l;
        if(l == r) r++;
        else sum -= a[l];
    }
    cout << ans << endl;
    return 0;
}