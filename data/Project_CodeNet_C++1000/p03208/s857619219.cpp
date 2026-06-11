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

int main() {
    cs
    int n,k,t=M;cin>>n>>k;
    vector<int> v(n+1);v[0]=0;
    repp(i,1,n) cin>>v[i];
    sort(v.begin(),v.end());
    repp(i,1,n-k+1) {
        t=min(t,v[i+k-1]-v[i]);
    }
    cout<<t;
}