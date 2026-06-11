#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;

int main() {
    int a,b,c;cin>>a>>b>>c;
    int mx=max({a,b,c});
    mx*=3;
    int sum=a+b+c;
    int ans=0;
    while(mx>sum){
        ans++;
        sum+=2;
    }
    while(sum%3!=0){
        ans++;
        sum+=2;
    }
    cout <<ans <<endl;
}