#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define drep(i,cc,n) for(int i=cc;i>n;--i)
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

ll cnt = 0;
ll n;

void dfs(ll cur){
    if(cur > n) return;

    ll tmp = cur;
    bool sev = false, fiv = false, thr = false;
    while(tmp!=0){
        if(tmp % 10 == 7) sev = true;
        if(tmp % 10 == 5) fiv = true;
        if(tmp % 10 == 3) thr = true;
        tmp = tmp / 10;
    }

    if(sev && fiv && thr) cnt++;

    dfs(cur * 10 + 7);
    dfs(cur * 10 + 5);
    dfs(cur * 10 + 3);
}

int main() {
    cin>>n;
    dfs(0);
    cout<<cnt<<endl;
    return 0;
}