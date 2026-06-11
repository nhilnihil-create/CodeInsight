#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>

int main() {
    ll N, Y;
    cin >> N >> Y;

    bool b = false;
    rep(i,N+1){
        rep(j,N - i + 1){
                if(!b && 10 * i + 5 * j + (N - i - j) == Y / 1000){
                    b = true;
                    cout << i << " " << j << " " << N - i - j << endl;
            }
        }
    }
    if(!b){
        cout << "-1 -1 -1" << endl;
    }
}