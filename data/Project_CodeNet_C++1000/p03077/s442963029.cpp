#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    ll n,a,b,c,d,e;
    cin>>n>>a>>b>>c>>d>>e;
    ll m=min(a,min(b,min(c,min(d,e))));
    cout<<5+n/m-(n%m==0)<<endl;
    return 0;
}