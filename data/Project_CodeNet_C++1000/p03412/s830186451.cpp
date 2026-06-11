#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 2e5;
int N;
int a[MAX_N+5], b[MAX_N+5];
int ca[MAX_N+5], cb[MAX_N+5];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<N;i++) cin >> b[i];

    ll ans = 0, p = 1;
    for(int i=0;i<30;i++){
        for(int j=0;j<N;j++){
            ca[j] = a[j] % (p<<1);
            cb[j] = b[j] % (p<<1);
        }

        sort(cb, cb+N);

        int cnt = 0;
        for(int j=0;j<N;j++){
            int d1 = distance(lower_bound(cb, cb+N, p-ca[j]), lower_bound(cb, cb+N, 2*p-ca[j]));
            int d2 = distance(lower_bound(cb, cb+N, 3*p-ca[j]), lower_bound(cb, cb+N, 4*p-ca[j]));
            cnt ^= (d1+d2) % 2;
        }

        if(cnt) ans += p;
        p <<= 1;
    }

    cout << ans << endl;
    return 0;
}
