#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
    int N, f = 0;
    cin >> N;

    rep(i, 9) {
        int p = pow(10,i);
        f += (N / p) % 10 ;
    }

    if(N % f) //ハーシャッド数でないとき
    cout << "No" << endl;
    else cout << "Yes" << endl;
}