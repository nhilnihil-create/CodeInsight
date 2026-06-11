#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    ll ans = 700;
    for(auto &ele:s)if(ele=='o')ans+=100;
    cout<<ans;
}
