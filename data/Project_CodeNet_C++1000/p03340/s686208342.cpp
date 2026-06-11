#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    int b[n][20]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<20;j++){
            if(a[i]%2)b[i][j]++;
            a[i]/=2;
        }
    }
    int x[20]={};
    int r=-1;
    long long ans=0;
    bool over;
    for(int l=0;l<n;l++){
        over=0;
        for(int i=0;i<20;i++)if(x[i]>1)over=1;
        while(r<n && over==0){
            r++;
            for(int i=0;i<20;i++)x[i]+=b[r][i];
            for(int i=0;i<20;i++)if(x[i]>1)over=1;
        }
        ans+=r-l;
        for(int i=0;i<20;i++)x[i]-=b[l][i];
    }
    cout<<ans<<endl;
    return 0;
}