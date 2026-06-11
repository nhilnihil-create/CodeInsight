#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    n--;
    int c[n],s[n],f[n];
    for(int i=0;i<n;i++)cin>>c[i]>>s[i]>>f[i];
    for(int i=0;i<n;i++){
        int t=c[i]+s[i];
        for(int j=i+1;j<n;j++)t=max(s[j],((t-1)/f[j]+1)*f[j])+c[j];
        cout<<t<<endl;
    }
    cout<<"0"<<endl;
    return 0;
}