#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n),x(n+1,0);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)x[a[i]]=x[a[i]-1]+1;
    int res=0;
    for(int i=0;i<n;i++)res=max(res,x[i+1]);
    cout<<n-res<<endl;
}