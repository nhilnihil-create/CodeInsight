#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    int n;cin>>n;
    int ans=0;
    vector<int>a(n);
    rep(i,n){
        cin>>a[i];
    }

    for (int i=n-1;i>0;i--) {
        if(a[i]==a[i-1]){
            a[i-1]=0;
            ans++;
        }
    }
    cout<<ans<<endl;
}

