#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll n,k,a,cnta[200000]={},nowk=0,cntb=0;
    cin>>n>>k;
    rep(i,n){
        cin>>a;
        a--;
        if(cnta[a]==0) nowk++;
        cnta[a]++;
    }
    sort(cnta,cnta+200000);
    rep(i,200000){
        if(nowk<=k) break;
        if(cnta[i]==0) continue;
        nowk--;
        cntb+=cnta[i];
    }
    cout<<cntb<<endl;
    return 0;
}