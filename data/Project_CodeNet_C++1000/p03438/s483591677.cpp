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

int main(){
    ll n,as=0,bs=0,k; cin>>n;
    vector<ll> a(n,0),b(n,0);
    rep(i,n){
        cin>>a[i]; as+=a[i];
    }
    rep(i,n){
        cin>>b[i]; bs+=b[i];
    }
    k=bs-as;
    rep(i,n){
        k-=max(0LL,(b[i]-a[i]+1)/2);
    }
    cout<<(k>=0 ? "Yes" : "No")<<endl;
}