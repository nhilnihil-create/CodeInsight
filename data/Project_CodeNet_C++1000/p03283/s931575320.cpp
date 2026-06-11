#include "bits/stdc++.h"
using namespace std;
int s[510][510];
int main(){
    int n,m,q;cin>>n>>m>>q;
    int l,r;
    for (int i=0; i<m; ++i){
        cin>>l>>r;
        for (int j=r; j<=500; ++j)++s[l][j];//累積和は後にふつうに求めたほうがいいかもしれないです。今回はどちらでも余裕
    }
    int ans;
    for (int i=0; i<q; ++i){
        cin>>l>>r;
        ans=0;
        for (int j=l; j<=r; ++j)
            ans+=s[j][r]-s[j][l-1];
        cout<<ans<<endl;
    }
}