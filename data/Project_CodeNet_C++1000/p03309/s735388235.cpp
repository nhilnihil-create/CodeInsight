#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll>a(n),aa(n);
    rep(i,0,n){
        cin>>a.at(i);
        aa.at(i)=a.at(i)-(i+1);
    }
    ll b;
    sort(all(aa));
    if(n%2==0)b=aa.at(n/2);
    else b=aa.at((n-1)/2);
    ll sum=0;
    rep(i,0,n){
        sum+=(abs(aa.at(i)-b));
    }
    cout<<sum<<endl;
return 0;
}