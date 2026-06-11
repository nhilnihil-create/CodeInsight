#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin>>n;
    vector<int>a(n);
    ll allsum=0;
    int tmp=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        allsum+=abs(a[i]-tmp);
        tmp=a[i];
    }
    allsum+=abs(a[n-1]);
    tmp=0;
    for(int i=0;i<n;i++){
        ll ans=allsum;
        if(i==n-1) ans=ans-abs(a[i]-tmp)-abs(a[i])+abs(a[i-1]);
        else ans=ans-abs(a[i]-tmp)-abs(a[i+1]-a[i])+abs(a[i+1]-tmp);
        tmp=a[i];
        cout<<ans<<endl;
    }
    return 0;
}