#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(n);i++)
using ll=long long;

int main() {
    int n;
    cin>>n;
    string ans="No";
    rep(i,25){
        rep(j,30)if(4*i+7*j==n)ans="Yes";
    }
    cout<<ans;
    return 0;
    }
