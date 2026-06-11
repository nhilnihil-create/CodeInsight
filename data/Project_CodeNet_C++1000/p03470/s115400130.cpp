#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    int cnt=1;
    rep(i,n-1){
        if(a[i]>a[i+1])++cnt;
    }
    cout<<cnt;

    return 0;
    }
