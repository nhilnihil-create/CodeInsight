#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll a,b; cin>>a>>b;
    char c='x';
    if(a+b==15) c='+';
    if(a*b==15) c='*';
    cout<<c<<endl;
    return 0;
}