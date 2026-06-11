#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    bool can=true;
    if(a[0]!=0)can=false;
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]>1)can=false;
    }
    int res=0;
    a.push_back(0);
    for(int i=0;i<n;i++){
        if(a[i]>=a[i+1])res+=a[i];
    }
    cout<<(can?res:-1)<<endl;
}