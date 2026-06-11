#include <bits/stdc++.h>
using namespace std;
long long N;
long long ans = 0;

void flag(long long M, bool ok1, bool ok2, bool ok3) {
    if (M > N) return;
    if (ok1) {
        if(ok2) {
            if(ok3) {
                ans++;
            }
        }
    }
    flag(10*M+3, true, ok2,  ok3);
    flag(10*M+5, ok1,  true, ok3);
    flag(10*M+7, ok1,  ok2, true);
}
  
int main() {
    cin >> N;
    flag(0, false , false , false);
    cout << ans << endl;
}