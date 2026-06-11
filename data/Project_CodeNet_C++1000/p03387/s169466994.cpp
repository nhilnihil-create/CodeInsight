#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;

int main() {
    V<int> v(3);
    for(int i = 0; i < 3; i++) cin >> v[i];
    sort(all(v));

    int x = v[2] - v[0];
    int y = v[2] - v[1];
    int a = 0, b = 0;
    if(x > 1){
        a = x / 2;
        x %= 2;
    }
    if(y > 1){
        b = y / 2;
        y %= 2;
    }
    int cnt = 0;
    if(x == 1 && y == 1) cnt++;
    else if(x == 1 || y == 1) cnt += 2;
    cout << cnt + a + b << endl;
}
