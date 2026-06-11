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
    ll n,cnt=0;
    string a,b,c;
    cin>>n>>a>>b>>c;
    vector<ll> s(n,0);
    rep(i,n){
        s[i] += a[i]==b[i];
        s[i] += b[i]==c[i];
        s[i] += c[i]==a[i];
        if(s[i]==1) cnt++;
        if(s[i]==0) cnt+=2; 
    }
    
    cout<<cnt<<endl;
    return 0;
}