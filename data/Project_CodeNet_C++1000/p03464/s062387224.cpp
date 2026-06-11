#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<ll>a(n),mx(n),mn(n);
    rep(i,n)cin>>a[i];
    reverse(a.begin(),a.end());
    if(a[0]>2){cout<<-1<<endl; return 0;}
    if(a[0]==2)mx[0]=3,mn[0]=2;
    for(int i=1; i<n; ++i){
        mx[i]=(mx[i-1]/a[i])*a[i]+a[i]-1;
        mn[i]=((mn[i-1]+a[i]-1)/a[i])*a[i];
        if(mx[i]<mn[i]){cout<<-1<<endl; return 0;}
    }
    cout<<mn[n-1]<<" "<<mx[n-1]<<endl;
}