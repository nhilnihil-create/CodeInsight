#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF=1001001001;
const ll LINF=1001001001001001001;
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(n) for(ll i=0;i<(n);++i)
#define rep2(i,n) for(ll i=0;i<(n);++i)
#define rep3(i,a,b) for(ll i=(a);i<(b);++i)
#define rep4(i,a,b,c) for(ll i=(a);i<(b);i+=(c))
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define vec vector<ll>
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}

string v="Vacant";
void solve(){
    ll n;cin>>n;
    cout<<0<<endl;
    string s;cin>>s;
    if(s==v)return;
    ll base=0;
    for(ll i=17;i>=0;i--){
        if(base+(1<<i)>=n)continue;
        cout<<base+(1<<i)<<endl;
        string t;cin>>t;
        if(t==v)return;
        if(t==s)base+=1<<i;
    }
}

int main(){
    solve();
}
