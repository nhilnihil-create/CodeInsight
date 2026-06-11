#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

ll gcd(ll p, ll q){ 
    while(q != 0){
        ll r=p%q;
        p=q;
        q=r;
    }
    return p;
}

int main(){
    ll n,a,b,c,d,e;
    cin>>n>>a>>b>>c>>d>>e;
    ll bn=min(e,min(d,min(c,min(a,b))));
    cout<<(n+(bn-1))/bn+4<<endl;
return 0;
}
