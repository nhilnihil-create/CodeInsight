#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a,const T &b){
    if(a>b)return false;
    a=b;
    return true;
}
template<class T>bool chmin(T &a,const T &b){
    if(a<b)return false;
    a=b;
    return true;
}

const ll mod=1e9+7;
const ll inf=1ll<<60;

/*---------------------*/

struct Edge{ll from,to,cost;};

int l;
vector<Edge>v;

int main(){
    cin>>l;
    int n=0;
    while(l>>n)n++;
    FOR(i,1,n){
        v.push_back({i,i+1,0});
        v.push_back({i,i+1,1<<(i-1)});
    }
    for(int i=n-1;i>=1;i--)if((l>>i-1)&1){
        v.push_back({i,n,l-(1<<i-1)});
        l-=(1<<i-1);
    }
    cout<<n<<" "<<v.size()<<endl;
    rep(i,v.size()){
        cout<<v[i].from<<" "<<v[i].to<<" "<<v[i].cost<<endl;
    }
}