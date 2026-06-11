#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

int main(){
    ll a,b; cin>>a>>b; b++;
    ll waru=2;
    ll bit=0LL;
    while(b/(waru/2)>0){
        ll atemp=a/waru * (waru/2) +  max(a%waru - waru/2,0LL);
        ll btemp=b/waru * (waru/2) +  max(b%waru - waru/2,0LL);
        if((btemp-atemp)%2==1) bit=(bit | (1LL<<((int)log2(waru) -1 )));
        waru*=2;
    }
    cout<<bit<<endl;
}