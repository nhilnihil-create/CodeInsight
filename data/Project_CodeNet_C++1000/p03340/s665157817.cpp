#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll sum=0,res=0,x=0;
    int l=0,r=0;
    for(;r<n;r++){
        x^=a[r];
        sum+=a[r];
        for(;sum!=x;l++){
            x^=a[l];
            sum-=a[l];
        }
        res+=r-l+1;
    }
    cout<<res<<endl;
}
