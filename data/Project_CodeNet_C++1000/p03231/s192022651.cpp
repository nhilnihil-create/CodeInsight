#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a % b);
}

int main(){
    ll n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    ll g = gcd(n,m);

    bool flag = true;
    ll ans = n*m/g;
    rep(i,g){
        if(s[i*n/g] != t[i*m/g]) flag = false;
    }
    if(flag) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}