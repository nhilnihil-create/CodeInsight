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
    bool checker = true;
    ll sum = 0;
    ll mini = INF;
    for(int i = 1; i <= n; i++){
        ll a, b;
        cin >> a >> b;
        sum += b;
        if(a > b){
            mini = min(mini, b);
            checker = false;
        }
    }
    if(checker){
        cout << 0 << endl;
        return 0;
    }
    cout << sum - mini << endl;
    return 0;
}
