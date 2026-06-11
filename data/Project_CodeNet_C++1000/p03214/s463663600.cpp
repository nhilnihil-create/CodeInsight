#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    double cnt=0,cnt2=1e9;
    rep(i,n){
        cin>>a[i];
        cnt+=a[i];
    }
    cnt/=n;
    int ans=-1;
    rep(i,n){
        double x=abs(cnt-a[i]);
        if(cnt2>x){
            cnt2=x;
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}