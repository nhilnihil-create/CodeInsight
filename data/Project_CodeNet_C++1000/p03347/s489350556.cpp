#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    a.push_back(-1);
    n++;
    ll ans=0;
    if(a[0]!=0){cout<<-1<<endl; return 0;}
    for(int i=1; i<n; ++i){
        if(a[i-1]+1<a[i]){cout<<-1<<endl; return 0;}
        else if(a[i-1]+1>a[i]){
            ans+=a[i-1];
        }
    }
    cout<<ans<<endl;
}