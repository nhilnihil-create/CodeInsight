#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long
#define endl '\n'

signed main() {
    int N;
    cin >> N;

    int h = 0,n = 0,w = 0;
    for(int i = 1; i <= 3500; i++){
        for(int j = 1; j <= 3500; j++){
            if((4 * i * j) % N != 0) continue;
            int X = i * j;
            int Y = (4 * i * j / N) - (i + j);
            if(Y == 0) continue;
            if(X % Y == 0 && X / Y > 0){
                h = i;
                n = j;
                w = X / Y;
                break;
            }
        }
    }
    cout << h << " " << n << " " << w << endl;

}