#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
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

vector<ll> ans(0);

void dfs(ll a){
    if(a>3234566667) return;
    ans.push_back(a);
    int m = a % 10;
    if(m>0) dfs(a*10 + m-1);
    dfs(a*10 + m);
    if(m<9) dfs(a*10 + m+1);
}

int main(){
    int a,b;
    cin>>a>>b;
    if(b%a==0) cout<<a+b<<endl;
    else cout<<b-a<<endl;
    return 0;
}