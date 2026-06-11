#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
ll MOD=1e9+7;

ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1) res=res*a%13;
        a=a*a%13;
        x>>=1;
    }
    return res;
}
int n;
ll f(ll x,int c3,int c5,int c7){
    if(x>n) return 0;
    ll res=0;
    if(c3>0&&c5>0&&c7>0) res+=1;
    res+=f(x*10+3,c3+1,c5,c7);
    res+=f(x*10+5,c3,c5+1,c7);
    res+=f(x*10+7,c3,c5,c7+1);
    return res;
}
int main(){
    cin>>n;
    cout<<f(0,0,0,0)<<endl;
    return 0;
}