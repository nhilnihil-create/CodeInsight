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

// 0始まりで0に戻るの本質だったのか

signed main(){
    int n;cin>>n;
    vector<int> l(n),r(n);
    rep(i,n)cin>>l[i]>>r[i];
    l.push_back(0);r.push_back(0);
    sort(ALL(l));reverse(ALL(l));
    sort(ALL(r));
    ll ans=0;
    rep(i,n+1){
        if(l[i]>r[i])ans+=2*(l[i]-r[i]);
    }
    cout<<ans<<endl;
    return 0;
}

/*

区間を損なく置ける場合，
res = 2*(sum(l of r)-sum(r of l))
損なく置く
->端の方の区間から処理していって損しない

sample 2
3
1 2
3 4
5 6

[1,2][3,4][5,6]

l:5 3 1 0 
r:0 2 4 6

2*(5-0)
0->->->->->5
 <-<-<-<-<-

2*(3-2)
2->3
 <-
*/
