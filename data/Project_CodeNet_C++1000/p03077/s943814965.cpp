#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=1000000000000000001;
int main(){
    ll n,a,b,c,d,e;cin>>n>>a>>b>>c>>d>>e;
    ll f=min(a,b);
    f=min(f,c);
    f=min(f,d);
    f=min(f,e);
    ll cnt=(n+f-1)/f;
    ll ans=cnt+4;
    cout << ans << endl;
}