#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;
#define INF 1e18LL

const ll MAX = 1000000000000000000; //1e18

int main(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k % 2 != 0){
        cout << b - a << endl;
    }else{
        cout << a - b << endl;
    }
}
