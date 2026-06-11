#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
ll func(ll n){
    if(n==0) return 0;
    else if(n%2!=0){
        if(((n+1)/2)%2!=0) return 1;
        else return 0;
    }
    else return func(n-1)^n;
}
int main(){
    ll a,b;
    cin>>a>>b;
    cout<<(func(b)^func(a-1))<<endl;
    return 0;
}