#define ONLINE_JUDGE
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
#define _overload3(_1,_2,_3,name,...) name
#define _rep2(i,n) for(ll i=0;i<(n);++i)
#define _rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,_rep3,_rep2)(__VA_ARGS__)
#define _repe2(i,n) for(ll i=0;i<=(n);++i)
#define _repe3(i,a,b) for(ll i=(a);i<=(b);++i)
#define repe(...) _overload3(__VA_ARGS__,_repe3,_repe2)(__VA_ARGS__)
#define _rrep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=(b)-1;i>=(a);i--)
#define rrep(...) _overload3(__VA_ARGS__,_rrep3,_rrep2)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
using pq=priority_queue<T,vector<T>,greater<T>>;
const string YES = "Yes";
const string NO = "No";

ll N;
ll M;
string s;
vl a;
vl b;

void solve();

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    cin >> M;
    cin >> s;
    a = vl(M);
    b = vl(M);
    for(int i = 0; i < M; ++i){
        cin >> a[i];
        cin >> b[i];
    }
    solve();
}

// 2 <= N <= 2 × 10^{5}
// 1 <= M <= 2 × 10^{5}
// |s| = N
// s_i は A または B
// 1 <= a_i, b_i <= N
// 与えられるグラフは単純とも連結とも限らない

// ll N, ll M, string s, vl a, vl b
// ヌスークが文字 A,B のみからなる任意の文字列が作ることが可能なら Yes を、そうでなければ No を出力せよ。
void solve(){
    vvl g(N),cnt(N,vl(2));
    rep(i,M){
        g[a[i]-1].push_back(b[i]-1);
        g[b[i]-1].push_back(a[i]-1);
        ++cnt[a[i]-1][s[b[i]-1]-'A'];
        if(a[i]!=b[i])++cnt[b[i]-1][s[a[i]-1]-'A'];
    }

    queue<ll> q;
    rep(i,N){
        if(!cnt[i][0]||!cnt[i][1])q.push(i);
    }

    ll rem_cnt=0;
    vl used(N);
    while(q.size()){
        ll x=q.front();q.pop();
        if(used[x])continue;
        ++rem_cnt;
        used[x]=true;
        for(ll to:g[x]){
            --cnt[to][s[x]-'A'];
            if(!cnt[to][s[x]-'A'])q.push(to);
        }
    }
    cout<<(rem_cnt<N?YES:NO)<<endl;
}
