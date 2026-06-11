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
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> a(m);
    rep(i,0,m-1) cin>>a[i];
    int cst1 = 0;
    int cst2 = 0;
    rep(i,0,m-1){
        if(a[i] < x) cst1++;
        else if(a[i] > x) cst2++;
    }
    cout<<min(cst1,cst2)<<endl;
    return 0;
}