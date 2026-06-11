#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<deque>
#include<functional>
#include<iterator>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define a first
#define b second
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(ll i=(n);i>=1;i--)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
const ll MOD=1000000007;
const ll INF=1000000000000000;
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return true;}return false;}
vector<ll> pw2(62,1);vector<ll> pw10(19,1);

int main(){
    {rep1(i,61) pw2[i]=2*pw2[i-1];}
    {rep1(i,18) pw10[i]=10*pw10[i-1];}
    
    ll N; cin>>N;
    ll ans=0;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    map<ll,ll> m1;
    map<ll,ll> m2;
    m1[0];
    m2[0];
    for(ll i=0;i<N;i+=2){
        m1[A[i]]++;
    }
    for(ll i=1;i<N;i+=2){
        m2[A[i]]++;
    }
    ll m1_1=0,m1_2=0,kind_1;
    for(auto it=m1.bg;it!=m1.ed;it++){
        if((it->b)>m1_1){
            m1_1=(it->b);
            kind_1=(it->a);
        }
    }
    for(auto it=m1.bg;it!=m1.ed;it++){
        if((it->a)!=kind_1 && (it->b)>m1_2){
            m1_2=(it->b);
        }
    }
    ll m2_1=0,m2_2=0,kind_2;
    for(auto it=m2.bg;it!=m2.ed;it++){
        if((it->b)>m2_1){
            m2_1=(it->b);
            kind_2=(it->a);
        }
    }
    for(auto it=m2.bg;it!=m2.ed;it++){
        if((it->a)!=kind_2 && (it->b)>m2_2){
            m2_2=(it->b);
        }
    }
    
    ll L=N/2;
    if(kind_1!=kind_2){
        cout<<L*2-m1_1-m2_1<<endl;
    }
    else{
        cout<<min(L*2-m1_1-m2_2, L*2-m1_2-m2_1)<<endl;
    }
}

