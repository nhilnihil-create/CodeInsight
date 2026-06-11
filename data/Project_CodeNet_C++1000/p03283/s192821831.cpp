#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int l[m],r[m],a[q],b[q];
    int x[n][n]={};
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i];
        x[0][r[i]-1]++;
        if(l[i]<n)x[l[i]][r[i]-1]--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++)x[i][j+1]+=x[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++)x[j+1][i]+=x[j][i];
    }
    for(int i=0;i<q;i++)cin>>a[i]>>b[i];
    for(int i=0;i<q;i++)cout<<x[a[i]-1][b[i]-1]<<endl;
    return 0;
}