#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, tmp, ans=0;
    cin >> N;
    for (int n = 1; n <= N; ++n){
        tmp = 0;
        if (n%2 == 0) continue;

        for (int i = 1; i <= n; ++i){
            if (n%i == 0) tmp += 1;
        }

        if (tmp==8) ans += 1;
    }
    cout << ans << endl;
}