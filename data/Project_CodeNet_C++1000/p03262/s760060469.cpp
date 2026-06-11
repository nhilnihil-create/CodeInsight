#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n);i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return(a%b)?gcd(b,a%b):b;}
ll lcm(ll a,ll b){return(a*b/gcd(a,b));}
const ll INF=1LL<<60;

int n,X;
vector<int> x(100100);

int main(){
    cin>>n>>X;
    rep(i,0,n){
        cin>>x[i];
        x[i]=abs(x[i]-X);
    }

    int g=gcd(x[0],x[1]);
    rep(i,2,n) g=gcd(g,x[i]);
    cout<<g<<"\n";
    return 0;
}
