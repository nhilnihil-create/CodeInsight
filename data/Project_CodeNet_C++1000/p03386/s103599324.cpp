#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL <<60;
typedef long long ll;
using namespace std;
 
ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}
 
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
 
ll choose2(ll n){
    return n*(n-1)/2;
}
 
int main() {
    ll a,b;
    int k;
    cin>>a>>b>>k;
    vector<ll> ans;

    int loop_max,loop_min;
    if(b - a <= k){
        loop_max = b;
        loop_min = a;
    }
    else{
        loop_max = a + k - 1;
        loop_min = b - k + 1;
    }

    rep(i,a,loop_max){
        ans.push_back(i);
        //cout<<i<<endl;
    }
    rep(i,loop_min,b){
        bool flag = true;
        rep(j,0,ans.size()-1){
            if(i == ans[j]) flag = false;
        }
        if(flag) ans.push_back(i);
    }

    sort(ans.begin(),ans.end());

    rep(i,0,ans.size()-1) cout<<ans[i]<<endl;

    return 0;
}