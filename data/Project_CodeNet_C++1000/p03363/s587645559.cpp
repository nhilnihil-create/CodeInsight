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

int main(){
    int n;cin >> n;
    vector<ll> a(n+1);
    map<ll,ll> ans;
    a[0]=0;
    ans[0]++;
    rep(i,n){
        int b;
        cin >> b;
        a[i+1]=a[i]+b;
        ans[a[i+1]]++;
    }
    ll cnt=0;
    for(auto v:ans){
        cnt+=v.second*(v.second-1)/2;
    }
    cout << cnt << endl;
}