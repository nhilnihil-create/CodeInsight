#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i < (int)n;++i)

int main() {
    int n,m,c;cin>>n>>m>>c;
    int b[m],a[m];
    int ans = 0;
    rep(i,m)cin>>b[i];
    
    rep(i,n){
        int tmp = c;
        rep(j,m){
            cin>>a[j];
            tmp+=a[j]*b[j];
        }
        if(tmp>0)++ans;
    }
    cout<<ans<<endl;
	return 0;
}