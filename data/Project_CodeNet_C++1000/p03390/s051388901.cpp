#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
bool solve(ll a, ll b, ll mid){
    if(mid < b){
        return true;
    }else{
        ll ana = ((mid + 1) / 2);
        ll bi = (mid + 2) / 2 + ((mid + 2) / 2 >= b ? 1 : 0);
        ll po = max(ana * bi, max((ana - 1) * (bi + 1), (ana + 1) * (bi - 1)));
        ll yo = (b + 1) * (mid - b + 1);
        if(max(po, yo) < a * b) return true;
        else return false;
    }
}
int main(){
    ll q;
    cin >> q;
    for(ll poyo = 0; poyo < q; poyo++){
        ll a, b;
        cin >> a >> b;
        if(a == b){
            cout << 2 * a - 2 << endl;
            continue;
        }
        if(a < b) a ^= b ^= a ^= b;
        ll low = 0, up = a + b - 2;
        while(up - low > 1){
            ll mid = (up + low) / 2;
            if(solve(a, b, mid)) low = mid;
            else up = mid;
        }
        cout << low << endl;
    }
    return 0;
}