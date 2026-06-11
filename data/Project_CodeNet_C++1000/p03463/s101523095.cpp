#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if(n==2){
        cout << "Borys";
    } else {
        if((b-a)%2==0)
            cout << "Alice";
        else
            cout << "Borys";
    }
    cout << endl;

    return 0;
}