#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    int l=1,r=n;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        l=max(l,a[i]);
        r=min(r,b[i]);
    }
    cout<<max(0,r-l+1)<<endl;
    return 0;
}
