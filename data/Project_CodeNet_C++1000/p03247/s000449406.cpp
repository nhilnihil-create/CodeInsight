#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    ll x[1050];
    ll y[1050];
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i < n; i++){
        if(abs((x[i] + y[i]) % 2) != (abs(x[i + 1] + y[i + 1]) % 2)){
            cout << -1 << endl;
            return 0;
        }
    }
    string last = "";
    ll beki[41];
    for(int i = 33; i <= 35; i++){
        beki[i] = 1;
    }
    for(int i = 32; i >= 0; i--){
        beki[i] = beki[i + 1] * 2;
    }
    int m = 33;
    bool checker = false;
    if(abs(x[1] + y[1]) % 2 == 0){
        m = 34;
        checker = true;
    }
    cout << m << endl;
    for(int i = 1; i <= m; i++){
        cout << beki[i];
        if(i < m){
            cout << " ";
        }
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        if(checker){
            x[i]++;
            last = "L";
        }
        ll u = x[i] + y[i];
        ll v = x[i] - y[i];
        for(int j = 1; j <= 33; j++){
            //cout << j << " " << beki[j] << " " << u << " " << v << endl;
            if((u > 0) && (v > 0)){
                cout << "R";
                u -= beki[j];
                v -= beki[j];
                continue;
            }
            if((u < 0) && (v > 0)){
                cout << "D";
                u += beki[j];
                v -= beki[j];
                continue;
            }
            if((u > 0) && (v < 0)){
                cout << "U";
                u -= beki[j];
                v += beki[j];
                continue;
            }
            cout << "L";
            u += beki[j];
            v += beki[j];
        }
        cout << last << endl;
    }
    return 0;
}