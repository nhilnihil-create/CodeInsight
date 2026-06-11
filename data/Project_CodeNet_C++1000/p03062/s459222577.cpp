#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1e9+7

int main(){
    int n;
    cin >> n;
    vi a(n);
    ll ans=0;
    int count=0;
    int mini=1e9+1;
    rep(i,n){
        cin >> a[i];
        if(a[i]<0){
            count++;
            a[i]*=-1;
        }
        ans+=a[i];
        mini=min(mini,a[i]);
    }
    if(count%2==0) cout << ans << endl;
    else cout << ans-2*mini << endl;

}