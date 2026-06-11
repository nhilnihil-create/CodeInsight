#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n; cin >> n;
    V<ll> c(n), s(n), f(n);
    for(int i = 0; i < n - 1; i++){
        cin >> c[i] >> s[i] >> f[i];
    }

    for(int i = 0; i < n - 1; i++){
        ll t = 0;
        for(int j = i; j < n - 1; j++){
            // sより小さければsで更新
            if(t < s[j]) t = s[j];
            else if(t % f[j] != 0){
                // ちょうど出発でなければ次の出発時間
                t += f[j] - (t % f[j]);
            }
            t += c[j];
        }
        cout << t << endl;
    }
    cout << 0 << endl;

    return 0;
}
