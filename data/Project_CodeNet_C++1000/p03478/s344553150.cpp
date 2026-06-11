#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int temp = i/10000 + (i%10000)/1000 + (i%1000)/100 + (i%100)/10 + (i%10);
        //cout << i << ':' << temp << endl;
        if(temp >= A && temp <= B) {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}