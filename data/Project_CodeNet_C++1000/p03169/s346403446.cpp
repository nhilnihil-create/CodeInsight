#include<bits/stdc++.h>
#define M 1000000007
#define pi ld(acos(-1.0))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(ll i=a;i<=(ll)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define bye(x) {cout<<x;return 0;}
typedef long long ll;
typedef long double ld;
using namespace std;
ld dp[303][303][303];int n;
ld solve(int a,int b,int c) {
    if(a<0||b<0||c<0||(!a&&!b&&!c)) return 0;
    if(dp[a][b][c]) return dp[a][b][c];
    ld t=n+a*solve(a-1,b,c)+b*solve(a+1,b-1,c)+c*solve(a,b+1,c-1);
    return dp[a][b][c]=t/(a+b+c);
}
int main() {
    cs
    int x;cin>>n;
    vector<int> v(3);
    rep(i,n) {
        cin>>x;
        v[x-1]++;
    }
    cout<<fixed<<setprecision(12)<<solve(v[0],v[1],v[2]);
}