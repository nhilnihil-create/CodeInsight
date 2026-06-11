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
   ll a,b;cin >>a>>b;
   ll k;cin >>k;
   rep(i,k){
    if(i%2==0){
        if(a%2==1)a--;
        a/=2;
        b+=a;
    }
    else {
        if(b%2==1)b--;
        b/=2;
        a+=b;
    }
   }
   cout << a << " "<<b<<endl;
    return 0;
}
