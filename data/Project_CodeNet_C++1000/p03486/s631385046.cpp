#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main() {
    string s,t;
    cin>>s>>t;
    
    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<int>());
    if(s<t)cout<<"Yes";
    else cout<<"No";
    
    return 0;
    }