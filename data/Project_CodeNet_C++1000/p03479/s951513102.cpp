#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll>f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b,s=0,x;
    cin>>a>>b;
    while(1ll<<s <= b/a){
        s++;
    }
    cout<<s<<endl;
    ///576460752303423488
}
