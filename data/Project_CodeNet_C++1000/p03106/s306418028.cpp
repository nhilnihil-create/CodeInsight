#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
    int a, b, k; cin >> a >> b >> k;
    int cnt = 0, ans = 0;
    for (int i = 100; i >= 1; i--){
        if (a % i == 0 && b % i == 0){
            cnt++;
            ans = i;
        }
        if (cnt == k) break;
    }
    cout << ans << endl;
}