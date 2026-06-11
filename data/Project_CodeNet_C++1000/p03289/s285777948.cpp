#include <iostream>
#include <string>
using namespace std;

bool isAC(const string &S) {
    if (S[0] != 'A') return false;

    int cnum = 0; // S の 3 文字目と末尾から 2 文字目の間の 'C' の個数
    bool exist = false; // S の先頭を除いた文字列が 'C' 以外の大文字を含むか

    // for 文の添字 i は、予め先頭 (0 文字目) を除外して 1 始まりとする
    for (int i = 1; i < S.size(); ++i) {
        // i が 3 文字目から末尾から 2 文字目の間の範囲にあるときを調べる
        if (i >= 2 && i + 1 < S.size() && S[i] == 'C') ++cnum;

        // 'C' 以外の大文字であるかどうか
        if (S[i] >= 'A' && S[i] <= 'Z' && S[i] != 'C') exist = true;
    }

    if (cnum != 1) return false;
    if (exist) return false;

    return true;
}

int main() {
    string S;
    cin >> S;
    if (isAC(S)) cout << "AC" << endl;
    else cout << "WA" << endl;
}