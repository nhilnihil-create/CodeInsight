#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
typedef priority_queue<string> priquest;
typedef priority_queue<string,vector<string>,greater<string>> rpriquest;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

const ll big=1000000007;
int exp(int x,int y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (exp(x,y-1)*x)%big;
    int t=exp(x,y/2);
    return (t*t)%big;
}
void chmin(ll a,ll b){
    if(a>b)a=b;
    return;
}
priority_queue<ll> div(ll m){
    priority_queue<ll> ans;
    for(int i=1;i*i<=m;i++){
        if(m%i==0){
            ans.push(i);ans.push(m/i);
        }
    }
    return ans;
}


int main(){
    //Mの約数であるのは明らか
    //d*N<=Mなる最大のdを取れば良い。
    ll n,m;cin >> n >> m;
    priority_queue<ll> ans=div(m);
    int s=ans.size();
    rep(i,s){
        ll k=ans.top();ans.pop();
        if(k*n<=m){printf("%lld\n",k);return 0;}
    }
}