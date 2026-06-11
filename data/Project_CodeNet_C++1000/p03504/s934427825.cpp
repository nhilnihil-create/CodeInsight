#include<iostream>
using namespace std;
int ooo[30][100001]={};
int main(){
    int n,c,s,t,x,r,ans=0;
    cin>>n>>c;
    
    for(int i=0;i<n;i++){
        cin>>s>>t>>x;
        ooo[x-1][s-1]++;ooo[x-1][t]--;
    }
    for(int i=0;i<c;i++){
        for(int j=1;j<=100000;j++)ooo[i][j]+=ooo[i][j-1];
        for(int j=0;j<=100000;j++)if(ooo[i][j])ooo[i][j]=1;
    }
    for(int i=1;i<=100000;i++){
        r=0;
        for(int j=0;j<c;j++)r+=ooo[j][i];
        ans=max(ans,r);
    }
    cout<<ans<<endl;
    return 0;
}