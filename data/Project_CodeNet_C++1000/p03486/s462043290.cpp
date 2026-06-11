#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    // Your code here!
    string s,t;
    cin>>s>>t;
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    if(s<t)cout<<"Yes";
    else cout<<"No";
}
