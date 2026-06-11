#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    ll g = __gcd(n,m);
    for(ll i=0;i<g;i++)if(s[i*(n/g)]!=t[i*(m/g)])return cout<<"-1" , 0;
    cout<<(n*m)/g;
}