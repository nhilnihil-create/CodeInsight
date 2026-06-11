#include <bits/stdc++.h>
using namespace std;

// n： 演算回数
// c: 答えをひとつだけ出すためのカウンタ
void find_seven(vector<int> &vec, string calc, int Sum, int n, int &c) {

    // 停止条件
    if (n == 4) {
        if (Sum == 7 && c == 0) {
            c++;
            cout << calc + "=7" << endl;
            return;
        }
        return;
    }

    // 処理
    int Sum_pl, Sum_mi;
    Sum_pl = Sum + vec.at(n);
    Sum_mi = Sum - vec.at(n);

    // 再帰
    find_seven(vec, calc + '+' + to_string(vec.at(n)), Sum_pl, n + 1, c);
    find_seven(vec, calc + '-' + to_string(vec.at(n)), Sum_mi, n + 1, c);
}


void show_calc(vector<int> &vec, int &c) {

    // 結果をここに埋め込む
    vector<string> calc(0);

    find_seven(vec, to_string(vec.at(0)), vec.at(0), 1, c);
}

int main() {

    string S;
    cin >> S;

    // 格納
    vector<int> vec(4);
    for (int i = 0; i < 4; i++) {
        char s = S.at(i);
        vec.at(i) = int(s) - 48; //数字は48から始まるらしい..
    }

    int c = 0;

    show_calc(vec, c);
}
