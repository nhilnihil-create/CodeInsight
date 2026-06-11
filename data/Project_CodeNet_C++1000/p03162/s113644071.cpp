#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][3];
    for(int i=0;i<n;i++)
     for(int j=0;j<3;j++)
      cin>>a[i][j];
    for(int i=1;i<n;i++)
    {
        a[i][0]+=max(a[i-1][1],a[i-1][2]);
        a[i][1]+=max(a[i-1][0],a[i-1][2]);
        a[i][2]+=max(a[i-1][0],a[i-1][1]);
    }
    cout<<max(a[n-1][0],max(a[n-1][1],a[n-1][2]))<<endl;
}