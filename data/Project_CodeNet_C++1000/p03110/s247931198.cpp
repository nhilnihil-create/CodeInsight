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
    sp(6);
    int n;cin>>n;
    double res=0;
    rep(i,n){
        double x;string s;cin>>x>>s;
        if(s=="BTC")x*=380000;
        res+=x;
    }
    cout<<res<<endl;
}
