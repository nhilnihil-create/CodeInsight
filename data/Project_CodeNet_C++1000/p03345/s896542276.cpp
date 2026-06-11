#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    if (k % 2 == 0) {
        cout << a - b << endl;
    }
    else{
        cout << b - a << endl;
    }
}