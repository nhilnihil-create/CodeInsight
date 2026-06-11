#include <iostream>
const int INF = 1e9;
using namespace std;

int main(void) {
    int N;
    string S;
    cin>>N>>S;
    // E[i] : i以下のEの個数、W[i] : i以下のWの個数
    int E[N + 1],W[N + 1];
    E[0] = 0;
    W[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == 'E') {
            E[i] = E[i - 1] + 1;
            W[i] = W[i - 1];
        }
        else {
            W[i] = W[i - 1] + 1;
            E[i] = E[i - 1];
        }
    }
    int mi = INF;
    // リーダの位置でループを回す
    for (int i = 1; i <= N; i++) {
        int num;
        num = W[i - 1] + (E[N] - E[i]);
        if (mi > num) mi = num;
    }
    cout << mi << endl;
    return 0;
}