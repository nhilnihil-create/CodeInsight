#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
    int n;
    map<ll,int> m;
    cin >> n;
    vector<ll> v(n);
    vector<ll> u(n+1);
    u[0]=0;
    rep(i,n){
        cin >> v[i];
    }
    m[0]++;
    //cout << 0 << " ";
    for (int i=1;i < n+1;i++){
        u[i]=u[i-1]+v[i-1];
        //cout << u[i] << " ";
        m[u[i]]++;
    }
    cout << endl;
    ll ans=0;
    for (auto w:m){
        ans+=((ll)w.second*(w.second-1)/2);
    }
    cout << ans << endl;

    return 0;
}