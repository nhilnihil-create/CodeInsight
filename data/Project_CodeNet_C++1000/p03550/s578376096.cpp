#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,z,w,a[2009];

int main(){
    cin>>n>>z>>w;
    FOR(i,1,n+1)cin>>a[i];
    a[0]=w;
    cout<<max(abs(w-a[n]),abs(a[n]-a[n-1]));
}