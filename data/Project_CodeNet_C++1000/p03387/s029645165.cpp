#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl = vector<ll>; using vvl = vector<vl>;
using vp = vector<pair<int,int>>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
const ll INF = 9223372036854775807;

int main() {
    int a,b,c;cin >> a >> b >> c;
    int t = a + b + c;
    int m = 3*max(max(a,b),c);
    if(t%2 != m%2) m += 3;
    cout << (m-t)/2 << endl;
}