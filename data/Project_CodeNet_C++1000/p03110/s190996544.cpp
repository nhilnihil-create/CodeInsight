#include <bits/stdc++.h>
using namespace std;

#define _overload3(_1, _2, _3, name, ...) name
#define repi(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(i, n) repi(i, 0, n)
#define REP(...) _overload3(__VA_ARGS__, repi, _rep,)(__VA_ARGS__)

typedef long long int ll;
typedef unsigned long long int ull;

const int MOD=(int)1e9+7;
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};

ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll g=gcd(a,b);return a/g*b;}
ll digitsum(ll a){ll x=0;while(a>0){x+=a%10;a/=10;}return x;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double sum=0;
    cin>>n;
    rep(i,n){
        string type;
        double u;
        cin>>u>>type;
        if(type=="BTC") sum=sum+(u*380000);
        else sum=sum+u;
    }
    printf("%f", sum);
}