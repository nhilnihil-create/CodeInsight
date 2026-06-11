#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    vector<ll> v;
    for(ll i = 1;i*i<N;i++){
        if(N%i != 0) continue;
        v.push_back(i);
        v.push_back(N/i);
        //ans += i-1;
        if(N/i - 1 > i){
            ans += N/i -1;
        }
    }

    cout << ans << endl;
    
}
