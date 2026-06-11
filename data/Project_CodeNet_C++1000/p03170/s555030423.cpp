#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    bool winsTaro[k+1];
    memset(winsTaro, false, sizeof(winsTaro));
    for(int i=0;i<n;i++)
        cin>>a[i];
    winsTaro[0]=false;
    for(int j=1;j<=k;j++) {
        for(int i=0;i<n;i++) {
            if(j-a[i]>=0)
                winsTaro[j]|=(!winsTaro[j-a[i]]);
        }
    }
    // for(int i=0;i<=k;i++)
    //     cout<<winsTaro[i]<<" ";
    // cout<<endl;
    if(winsTaro[k])
        cout<<"First"<<endl;
    else 
        cout<<"Second"<<endl;
}