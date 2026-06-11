#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if(b == 1){
        if(a != n){
            cout << -1 << endl;
            return 0;
        }else{
            rep(i, n)cout << i + 1 << ' ';
            cout << endl;
            return 0;
        }
    }else if(a == 1){
        if(b != n){
            cout << -1 << endl;
            return 0;
        }else{
            rep(i, n)cout << n - i << ' ';
            cout << endl;
            return 0;
        }
    }else{
        if(n < a + b - 1 || n > a * b){
            cout << -1 << endl;
            return 0;
        }
    }

    int c = (n - b) % (a - 1);
    int d = (n - b) / (a - 1);
    int cnt = 0;
    rep(i, a){
        if(i == 0){
            rep(j, b){
                cout << cnt + b - j << ' ';
            }
            cnt += b;
        }else if(i <= c){
            rep(j, d+1){
                cout << cnt + d + 1 - j << ' ';
            }
            cnt += d + 1;
        }else{
            rep(j, d){
                cout << cnt + d - j << ' ';
            }
            cnt += d;
        }
    }
    cout << endl;
}