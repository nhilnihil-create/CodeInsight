#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int n , a , b;
    cin >> n >> a >> b;
    if(n < a + b){
        cout << min(a , b) << ' ' << a + b - n << endl;
    }
    else{
        cout << min(a , b) << ' ' << 0 << endl;
    }
}
