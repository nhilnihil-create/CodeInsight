
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    ll n; cin >> n;
    int fx=0, temp=n;
    rep(i,8){
        fx += temp % 10;
        temp /= 10;
    }
    if(n % fx == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

}