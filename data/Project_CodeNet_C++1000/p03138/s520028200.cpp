#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int n;
    typedef  unsigned long long ll;
    ll k;
    cin >> n >> k;
    vector<ll> vecA(n);
    for(int i = 0; i < n; i++){
        cin >> vecA.at(i);
    }

    ll res = 0;

    for (int d = 40; d >= -1; --d){
        if(d != -1 && !(k & (1LL<<d))) continue;

        ll tmp = 0;

        for(int e = 40; e >= 0; --e){
            ll mask = 1LL<<e;
            int num = 0;
            for (int i = 0; i < n; ++i) if (vecA[i] & mask) ++num;

            if (e > d) {
                if (k & mask) tmp += mask * (n - num);
                else tmp += mask * num;
            }
            else if (e == d) {
                tmp += mask * num;
            }
            else {
                tmp += mask * max(num, n - num);
            }
        }
     res = max(res, tmp);
    }
    cout << res << endl;
    return 0;
}