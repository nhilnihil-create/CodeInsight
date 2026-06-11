#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) (v).begin(),(v).end()
#define out(a) cout << (a) << endl
using namespace std;
using ll = long long;
int main(){
    ll x, y;
    cin >> x >> y;
    int cnt=0;
    while(x <= y){
        x *= 2;
        cnt++;
    }
    out(cnt);

}