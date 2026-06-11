#include <bits/stdc++.h>

#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,p,ans=1;
    ll g[1000000]={0};
    cin>>n>>p;
    if(n>=63){
        cout << 1<<endl;
        return 0;
    }
    ll a = 2;
    while (p >= a * a) {
        if (p % a == 0) {
            g[a]++;
            p /= a;
        } else {
            a++;
        }
    }
    if(p!=1 && n==1){
        ans*=p;
    }
    else{
        if(p<1000000){
            g[p]++;
        }
    }
    for(int i=2;i<999999;i++){
        if(g[i]!=0){
            ans*=pow(i,(g[i]/n));
        }
    }
    cout << ans<<endl;

    return 0;
}
