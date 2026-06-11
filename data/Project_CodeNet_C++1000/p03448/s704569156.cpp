#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int a,b,c,x;cin>>a>>b>>c>>x;
    int ans = 0;
    rep(i,a+1)rep(j,b+1)rep(k,c+1)if(500*i+100*j+50*k==x)ans++;
    co(ans);
}