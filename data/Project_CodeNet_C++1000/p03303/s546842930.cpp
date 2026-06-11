#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s,ans="";cin>>s;
    ll k;cin>>k;
    ll n=s.size(),cur=0;
    while(cur<n){
        ans+=s[cur];
        cur+=k;
    }
    cout<<ans;
}