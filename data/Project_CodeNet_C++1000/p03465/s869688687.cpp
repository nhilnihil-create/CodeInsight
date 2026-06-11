#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    bitset<4000001> bit(1);
    ll n,a,sum=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a;
        bit|=(bit<<a);
        sum+=a;
    }
    for(ll i=(sum+1)/2;;i++){
        if(bit[i]==1){
            cout << i<<endl;
            return 0;
        }
    }
    return 0;
}
