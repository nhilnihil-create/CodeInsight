#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define vvl vector<vector<ll>> //a(縦行,vector<ll>(横列));
#include<algorithm>//__gcd(a,b)

int main(){
    ll n,m;cin>>n>>m;

    if(n==1&&m>1)cout<<m-2<<endl;
if(n>1&&m==1)cout<<n-2<<endl;
if(n==1&&m==1)cout<<1<<endl;
    if(n>1&&m>1)cout<<(n-2)*(m-2)<<endl;

}
