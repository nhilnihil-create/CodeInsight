#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,a=0;cin>>n;
    string s;cin>>s;
    for(ll i=0;i<n;i++)if(s[i]=='R')a++;
    cout<<(a>n-a?"Yes":"No");
}


