#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    int X;
    cin >> X;
    int ans = 1;
    for (int i = 2; i <= pow(X, 0.5); i++) {
        int cnt = i;
        while (cnt <= X){
            if (cnt*i <= X) {
                cnt *= i;
            }
            else{
                break;
            }
        }
        ans = max(ans,cnt);
        if (ans == X) {
            break;
        }
    }
    cout << ans << endl;
}
