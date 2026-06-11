#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;
#define MOD 1000000007;

long long gcd(long long a, long long b) { // 2つの場合の最大公約数
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
 
long long gcd_vec(vector<long long> const &A) { // N個の要素に対する最大公約数
    int size = (int)A.size();
    long long ret = A[0];
    for (int i = 1; i < size; i++) {
        ret = gcd(ret, A[i]);
    }
    return ret;
}

int main() {

int N;
cin>>N;
vector<ll> A(N);
rep(i,N){
    cin>>A[i];
}

cout<<gcd_vec(A)<<endl;



return 0;
}