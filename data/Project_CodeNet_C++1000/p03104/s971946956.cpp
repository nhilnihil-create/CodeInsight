#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

ll x(ll n){
    if(n%4==0)return n;
    else if(n%4==1)return 1;
    else if(n%4==2)return n+1;
    else return 0;
}

int main(){
    ll a,b;
    cin>>a>>b;
    cout<<(x(a-1)^x(b))<<endl;
return 0;
}