#include <bits/stdc++.h>
using namespace std;

int N;
int ans = 0;

int main() {
    cin >> N;
    for (int n = 1; n <= N; n+=2){
        int div = 0;
        for (int i = 1; i <= n; i++){
            if (n % i == 0){
                div += 1;
            }
        }
        if (div == 8){
            ans += 1;
        }
    }
    cout << ans << endl;
}
