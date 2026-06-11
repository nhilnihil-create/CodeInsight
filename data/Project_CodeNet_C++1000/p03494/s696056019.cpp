#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i, n)cin>>a[i];
    bool t=0;
    int ans=0;
    do{
        int cnt=0;
        rep(i, n){
            if(a[i]!=0 && a[i]%2==0)
            {
                a[i]/=2;
                cnt++;
            }
        }
        if(cnt==a.size())
        {
            ans++;
            t=1;
        }
        else t=0;

    }
    while(t);
    cout<<ans;
    
    return 0;
    }