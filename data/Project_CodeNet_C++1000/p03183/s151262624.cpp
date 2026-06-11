#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define mod 1000000007
using ll=long long;
const int INF=1000000000;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}
 
struct IOSetup{
    IOSetup(){
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout<<fixed<<setprecision(12);
    }
} iosetup;
 
template<typename T1,typename T2>
ostream &operator<<(ostream &os,const pair<T1,T2>&p){
    os<<p.first<<" "<<p.second;
    return os;
}
 
template<typename T>
ostream &operator<<(ostream &os,const vector<T>&v){
    for(int i=0;i<(int)v.size();i++) os<<v[i]<<(i+1==(int)v.size()?"":" ");
    return os;
}

template<typename T1,typename T2>
istream &operator>>(istream &is,pair<T1,T2>&p){
    is>>p.first>>p.second;
    return is;
}

template<typename T>
istream &operator>>(istream &is,vector<T>&v){
    for(T &x:v)is>>x;
    return is;
}




struct Block{
    int w,s;ll v;
    Block(int w,int s,ll v):w(w),s(s),v(v){}
    Block(){}
};

const int OV=11000;
ll dp[1100][11100];

signed main(){
    int n;cin>>n;
    vector<Block>a(n);
    rep(i,n){
        int w,s;ll v;cin>>w>>s>>v;
        a[i]=Block(w,s,v);
    }

    sort(ALL(a),[](Block lhs,Block rhs){
        return lhs.w+lhs.s<rhs.w+rhs.s;
    });

    rep(i,n){
        rep(j,OV+1){
            if(j<=a[i].s){
                int to=min(OV,j+a[i].w);
                chmax(dp[i+1][to],dp[i][j]+a[i].v);
            }
            chmax(dp[i+1][j],dp[i][j]);
        }
    }
    ll res=0;
    rep(j,OV+1)chmax(res,dp[n][j]);
    cout<<res<<endl;
    return 0;
}



/*
s+wでソートするのが嬉しい証明
今，上に重みWがすでに積まれていて，次にaとbのどっちのBlockを置くか考える
この時，a->bで置くと，両方置けて，b->aで置くと両方置けない．
つまり，aから観たほうが得である状況を考える
(どっちから先に置いたところで片方しか置けない状況，両方置けない状況を考えるのは意味がない．
ソートの順序を考える上でどうでもよい)

a->bで両方置ける．
s_a>=w and s_b>=w+w_a  ... (i)
b->aだと両方置けない．
not(s_b>=w and s_a>=w+w_b) <=> s_b<w or s_a<w+w_b   ...(ii)
(i)よりs_b<wとなることはない．変数全部非負であるため，よって得にの状況に差が出るのは
(i) and s_a<w+w_b
変形すると，
s_a-w_b<w<=s_b-w_a
<=>  s_a+w_a<=s_b+w_b
よってs+wでソートして，小さいほうから見るのがよい
*/