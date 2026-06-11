//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

ll gcd(ll a,ll b){
    ll temp;
    while(b){
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main(){
    int n,ans=0; cin>>n;
    map<int,int> m;
    rep(i,n){
        int a; cin>>a;
        if(!(m.count(a))) m[a]=0;
        m[a]++;
    } 
    for(auto q:m){
        if(q.first<=q.second) ans+=q.second-q.first;
        else ans+=q.second;
    }
    cout<<ans<<endl;
}