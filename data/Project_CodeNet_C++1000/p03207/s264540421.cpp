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
    vector<int> p(n);
    rep(i,n) cin>>p[i];
    sort(p.rbegin(),p.rend());
    int res=0;
    rep(i,n){
        if(i==0)res+=p[i]/2;
        else res+=p[i];
    }
    cout<<res<<endl;
}
