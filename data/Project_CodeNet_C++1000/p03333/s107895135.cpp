#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<ll> L(N),R(N);
    for(int i=0;i<N;i++) cin >> L[i] >> R[i];
    sort(L.begin(),L.end(),greater<ll>());
    sort(R.begin(),R.end());
    ll ans = 0,now1 = 0,now2 = 0;
    for(int i=0;i<N;i++){
        now1 += 2*L[i];
        now2 -= 2*R[i];
        ans = max({ans,now1,now2});
        now1 -= 2*R[i];
        now2 += 2*L[i];
        ans = max({ans,now1,now2});
    }
    cout << ans << endl;
}