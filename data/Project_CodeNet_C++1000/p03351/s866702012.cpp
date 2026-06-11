#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1005;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll a,b,c,d;cin>>a>>b>>c>>d;
    if(abs(a-c)<=d || (abs(a-b)<=d && abs(b-c)<=d) )cout<<"Yes";
    else cout<<"No";
}
