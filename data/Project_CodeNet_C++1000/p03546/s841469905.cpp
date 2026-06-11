#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    int c[10][10];
    for(int i=0;i<10;i++)for(int j=0;j<10;j++)cin>>c[i][j];
    for(int k=0;k<10;k++)for(int i=0;i<10;i++)for(int j=0;j<10;j++)c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
    int a[h][w];
    int x=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            if(a[i][j]!=1 && a[i][j]!=-1)x+=c[a[i][j]][1];
        }
    }
    cout<<x<<endl;
    return 0;
}