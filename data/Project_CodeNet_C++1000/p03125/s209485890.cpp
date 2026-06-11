#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i< (n); ++i)
const int INF = 1001001001;

/*
 *
 * */

int main() {
    int A, B;
    cin >> A >> B;

    int ans = 0;
    if(B%A == 0) {
        ans = A + B;
    }else{
        ans = B-A;
    }
    cout << ans << endl;
    return 0;
}
