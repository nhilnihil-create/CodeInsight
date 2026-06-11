#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    vector<bool>ok(X+1);
    ok[1] = 1;
    for(int i = 2; i*i <= X; i++) {
        ok[i*i] = 1;
        int cnt = i*i*i;
        while(cnt <= X) {
            ok[cnt] = 1;
            cnt *= i;
        }
    }
    for(int i = X; i >= 1; i--) {
        if(ok[i]) {
            cout << i << endl;
            return 0;
        }
    }
} 
