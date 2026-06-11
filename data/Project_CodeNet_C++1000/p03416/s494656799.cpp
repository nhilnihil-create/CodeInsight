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
    int ans = 0;
    for(int i = a; i <= b; i++) {
        if(i / 10000 == i % 10 && i / 1000 % 10 == i / 10 % 10) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}