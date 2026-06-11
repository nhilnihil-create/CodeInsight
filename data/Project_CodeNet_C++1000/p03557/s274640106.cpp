#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n;
cin>>n;
vector<int>a(n),b(n),c(n);
rep(i,n)cin>>a[i];
rep(i,n)cin>>b[i];
rep(i,n)cin>>c[i];
sort(a.begin(),a.end());
sort(b.begin(),b.end());
sort(c.begin(),c.end());
ll ans=0;
rep(i,n){
    int _b=b[i];
    auto iter_a = lower_bound(a.begin(),a.end(),_b);
    auto iter_c = upper_bound(c.begin(),c.end(),_b);
    int dist=a.end()-iter_a;
    dist=c.end()-iter_c;
    ans+=(n-int(a.end()-iter_a))*(c.end()-iter_c);
}
cout<<ans<<endl;
return 0;
}