using namespace std;
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < int(n); i++)

int main() {
    int a, b, k; cin >> a >> b >> k;
    int cnt = 0;
    for(int i = a; i <= min(a+k, b); i++){
        cout << i << endl;
        cnt ++; 
        if (cnt >= k) break;
    }
    cnt = 0;
    for(int i = max(0, b-k+1); i <= b; i++){
        if (i <= a+k-1) continue;
        cout << i << endl;
        cnt ++;
        if (cnt >= k) break;
    }
}