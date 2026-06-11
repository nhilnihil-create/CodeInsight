#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    ll sa=0,sb=0;
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b[i];
    }

    ll ba=0,bb=0;
    rep(i,n){
        if(a[i]>b[i]) ba+=a[i]-b[i];
        if(b[i]>a[i]) bb+=(b[i]-a[i])/2;
    }

    if(bb>=ba) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
} 
