#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<=(n);i++)
using ll=long long;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    
    sort(a.begin(),a.end());
    cout<<a[a.size()-1]-a[0];
    

    
    return 0;
    }
