#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int f[n][10],p[n][10];
    for(int i=0;i<n;i++)for(int j=0;j<10;j++)cin>>f[i][j];
    for(int i=0;i<n;i++)for(int j=0;j<=10;j++)cin>>p[i][j];
    int m=-1000000000;
    for(int i=1;i<1024;i++){
        int money=0,I=i;
        int same[n]={};
        for(int j=0;j<10;j++){
            if(I%2){
                for(int k=0;k<n;k++)if(f[k][j])same[k]++;
            }
            I/=2;
        }
        for(int j=0;j<n;j++)money+=p[j][same[j]];
        m=max(m,money);
    }
    cout<<m<<endl;
    return 0;
}