#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,a,ans=0,num,maki;
    cin>>n;
    multiset<ll> ms;
    for(int i=0;i<n;i++){
        cin>>a;
        ms.insert(a);
    }
    while(!ms.empty()){
        num=*ms.rbegin();
        ms.erase(ms.find(num));
        maki=1;
        while(maki<=num)maki*=2;
        if(ms.count(maki-num)){
            ms.erase(ms.find(maki-num));
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
