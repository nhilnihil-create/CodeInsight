#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n){
        cin>>a[i];
    }
    ll al = pow(3,n);
    ll od = 1;
    rep(i,n){
        ll cnt = 0;
        if(a[i]%2!=0) cnt++;
        if((a[i]-1)%2!=0) cnt++;
        if((a[i]+1)%2!=0) cnt++;
        od*=cnt;
    }
    cout<<al-od<<endl;
    return 0;
}
