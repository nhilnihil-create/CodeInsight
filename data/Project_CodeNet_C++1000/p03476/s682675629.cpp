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

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
int A[1000001];
A[0]=1;
rep3(i,100000){
    if((is_prime(i))&&(is_prime((i+1)/2))){
        A[i]=A[i-1]+1;
    }
    else{
        A[i]=A[i-1];
    }

}
int Q;
cin>>Q;
int ans[Q];
rep(i,Q){
    int l,r;
    cin>>l>>r;
    ans[i]=A[r]-A[l-1];

}
rep(i,Q){
    cout<<ans[i]<<endl;
}
    
return 0;
}