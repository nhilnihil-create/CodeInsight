#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll x,y;
    cin>>x>>y;
    ll now=x,cnt=1;
    while(now*2<=y){
        now*=2;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}