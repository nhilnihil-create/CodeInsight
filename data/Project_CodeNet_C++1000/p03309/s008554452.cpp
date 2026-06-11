
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n) cin>>A[i];
    vector<int> a(n);
    rep(i,n) a[i]=A[i]-i-1;
    sort(a.begin(),a.end());
    int h=n/2;
    int b=a[h];
    ll ans=0;
    rep(i,n) ans+=abs(A[i]-b-i-1);
    cout<<ans<<endl;
    return 0;
}
