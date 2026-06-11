#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n; cin>>n;
    if(n/10%111==0 || n%1000%111==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}