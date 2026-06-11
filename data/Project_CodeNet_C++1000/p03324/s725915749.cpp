#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, d;
    cin >> d >> n;
    if(d == 0) {
        if(n == 100) cout << 101 << endl;
        else cout << n << endl;
    }
    else if(d == 1) {
        if(n == 100) cout << 10100 << endl;
        else cout << n * 100 << endl;
    }
    else {
        if(n == 100) cout << 1010000 << endl;
        else cout << n * 10000 << endl;
    }
    return 0;
}