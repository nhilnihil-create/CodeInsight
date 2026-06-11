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
    int a, b;
    cin >> a >> b;
    int x = (a * 10 + b * 10) / 2;
    if(x % 10 == 0) {
        cout << x / 10 << endl;
    }
    else {
        cout << x / 10 + 1<< endl;
    }

    return 0;
}