#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    //まず0番目をリーダーにしたときを数える
    int turn = 0;
    for (int i=1; i<n; i++) {
        if (s[i] == 'E') {
            turn++;
        }
    }
    int minTurn = turn;
    //1,2,3,...番目をリーダーにした時、向き変えの必要数の変化を考える
    for (int i=1; i<n; i++) {
        if (s[i-1] == 'W') {
            turn++;
        }
        if (s[i] == 'E') {
            turn--;
        }
        minTurn = min(minTurn, turn);
    }
    cout << minTurn << endl;
}