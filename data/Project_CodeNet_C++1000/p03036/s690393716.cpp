#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int r , d , a;
    cin >> r >> d >> a;
    for(int i = 0; i < 10; i++){
        a = r * a - d;
        cout << a << endl;
    }
}