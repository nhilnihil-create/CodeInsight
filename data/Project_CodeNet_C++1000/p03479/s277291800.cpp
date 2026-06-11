
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll x, y;
    cin >> x >> y;
    int ans=0;
    while(true){
        ans ++;
        y /=2;
        if(x>y){
            break;
        }
    }

    cout << ans << endl;
}