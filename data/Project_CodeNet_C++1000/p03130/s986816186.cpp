#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    vector<int> counter(5, 0);
    rep(i, 3) {
        int a, b;
        cin >> a >> b;
        counter[a]++;
        counter[b]++;
    }
    int one = 0, two = 0;
    for (int i = 1; i <= 4; i++) {
        if (counter[i] == 1) one++;
        if (counter[i] == 2) two++;
    }
    if(one == 2 && two == 2){
        puts("YES");
    }else {
        puts("NO");
    }
}