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

void exp(){
    int n;cin>>n;
    vector<int> v(n);
    cin>>v;
    vector<int> s;
    for(int bit=1;bit<(1<<n);bit++){
        int res=0;
        rep(i,n)if((bit>>i)&1)res+=v[i];
        s.push_back(res);
    }
    sort(ALL(s));
    debug(s);
    cout<<s[(1<<(n-1))-1]<<endl;

    map<int,int> cnt;
    for(auto x:s)cnt[x]++;
    for(auto p:cnt)cout<<p.first<<" : "<<p.second<<endl;
}

const int M=4000010;

signed main(){
    int n;cin>>n;
    vector<int> a(n);
    cin>>a;
    int s=0;
    rep(i,n)s+=a[i];
    bitset<M> bs;
    bs[0]=1;
    rep(i,n)bs|=(bs<<a[i]);
    for(int i=(s+1)/2;i<M;i++)if(bs[i]){
        cout<<i<<endl;
        return 0;
    }
}

/*
4
1 1 3 6
Σa=11
空集合も許容すると
S={0,1,1,2,3,4,4,5,6,7,7,8,9,10,10,11}
0  1  1  2 3 4 4 5
11 10 10 9 8 7 7 6
答えは，Σa/2以上で存在する最も小さな値
DPをbitset高速化
*/