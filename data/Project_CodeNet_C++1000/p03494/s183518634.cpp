#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N, n = 30;
    cin >> N;

    rep (i, N) { //数字の数だけ繰り返す
        int a;
        cin >> a;
        rep (j, n) { //各数字が2で割れる回数を数えてnに戻す
            if (a % 2 == 0){
                a /= 2;
            }

            else {n = j;
            break;
            }
        }
    }
    //nが最小値に収束
    cout << n << endl;
}