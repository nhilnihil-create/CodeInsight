
#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
int main(void){
    int n,x;
    cin>>n>>x;
    vector<ll> a(n);
    ll mindist=INF;
    rep(i,0,n){
        cin>>a[i];
        mindist=min(mindist,abs(x-a[i]));
    }

    for(int i=mindist;i>0;i--){
        bool ok;
        rep(j,0,n){
            if(abs(x-a[j])%i==0)ok=true;
            else {ok=false;break;}
        }
        if(ok){
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}