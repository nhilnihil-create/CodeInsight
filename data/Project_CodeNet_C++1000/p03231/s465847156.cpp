#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);


long long gcd(long long a, long long b) {
   if (a%b == 0) {
       return(b);
   }
   else {
       return(gcd(b, a%b));
   }
}

long long lcm(long long a, long long b) {
   long long tmp = max(a,b)/gcd(a,b);
   return min(a,b)*tmp;}

int main() {
    ll N,M;
    cin >> N >> M;
    string S,T;
    cin >> S >> T;

    ll L = lcm(N,M);

    map<ll,char> X;

    bool t = true;

    rep(i,N) {
        ll idx = 1 + i*(L/N);
        X[idx] = S[i];
    }
    rep(i,M) {
        ll idx = 1 + i*(L/M);
        if (!X.count(idx)) continue;
        else if (X[idx]!=T[i]) t = false;
    }

    if (t) cout << L << endl;
    else cout << -1 << endl;
        
}