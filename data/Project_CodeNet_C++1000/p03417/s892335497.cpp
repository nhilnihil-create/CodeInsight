#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n,m;
    cin>>n>>m;
    cout<<(min(n,m)==1?(n*m==1?1:max(n,m)-2):n*m-2*n-2*m+4)<<endl;
    return 0;
}