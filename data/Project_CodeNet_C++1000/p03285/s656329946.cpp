#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    bool ans = false;
    for (int i = 0; i <= 25; i++) {
        for (int j = 0; j <= 15; j++) {
            if (4 * i + 7 * j == N) ans = true;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}