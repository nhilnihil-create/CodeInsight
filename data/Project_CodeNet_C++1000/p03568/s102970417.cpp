#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a;
    ll ans=1,num=1;
    for(int i=0;i<n;i++){
        cin>>a;
        ans*=3;
        if(a%2==0){
            num*=2;
        }
    }
    cout <<ans-num<<endl;
    return 0;
}
