#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

int main() {
    int a,b;
    double t;
    cin >> a >> b >> t;
    t += 0.5;
    int cnt = 0;
    int sec = 0;
    while(sec+a < t){
        cnt += b;
        sec += a;
    }
    cout << cnt << endl;
}

