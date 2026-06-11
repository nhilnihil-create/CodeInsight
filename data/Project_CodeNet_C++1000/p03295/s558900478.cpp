#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    pair<int,int> p[m];
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        p[i]={b[i],a[i]};
    }
    sort(p,p+m);
    int ans=1,x=p[0].first;
    for(int i=1;i<m;i++){
        if(p[i].second>=x){
            ans++;
            x=p[i].first;
        }
    }
    cout<<ans<<endl;
    return 0;
}