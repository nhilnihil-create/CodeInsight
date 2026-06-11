#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int K;
    cin >> K;

    if(K % 2 == 0) {
        cout << (K / 2) * (K / 2);
    }else {
        cout << (1 + (K - 1) / 2)* (K - 1) / 2;
    }
   return 0;
}