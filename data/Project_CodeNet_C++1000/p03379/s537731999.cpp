#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int>x(n),a(n),b(n);
    rep(i,n){
        cin>>x[i];
        a[i]=x[i];
    }
    sort(a.begin(),a.end());
    rep(i,n){
        if(x[i]<=a[n/2-1])cout<<a[n/2]<<endl;
        else cout<<a[n/2-1]<<endl;
    }
}