#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k,a,b[100]={};
    int ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a;
            b[a]++;
        }
    }
    for(int i=1;i<=m;i++){
        if(b[i]==n){
            ans++;
        }
    } 
    cout<<ans<<endl;
    return(0);
}