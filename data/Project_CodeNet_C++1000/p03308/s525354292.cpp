#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    int ans;
    ans=abs(a[0]-a[n-1]);
    cout<<ans<<endl;
}