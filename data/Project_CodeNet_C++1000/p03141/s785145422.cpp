#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n;cin>>n;
    ll a[100010],b[100010];
    rep(i,0,n)cin>>a[i]>>b[i];
    vector<pair<ll,ll> > c(n);
    rep(i,0,n){c.at(i).first=a[i]+b[i];c.at(i).second=i;}
    sort(c.begin(),c.end(),greater<>());
    ll an=0;
    rep(i,0,n){
        if(i%2==0){
            an+=a[c.at(i).second];
        }
        else{
            an-=b[c.at(i).second];
        }
    }
    cout<<an<<endl;
}





