#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod = int(1e9)+7;
using V = vector<ll>;
using P = pair<ll,ll>;

int main()
{
   ll x,y;cin >>x>>y;
   ll g=__gcd(x,y);
   ll a=x/g,b=y/g;
   if(a%b==0){
    cout <<-1<< endl;
   }
   else cout <<x*a<< endl;
    return 0;
}
