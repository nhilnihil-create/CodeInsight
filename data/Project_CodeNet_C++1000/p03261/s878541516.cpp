#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    int n;
    cin >> n;
    string word, previous_word;
    bool flag = true;
    map<string, bool> history;
    cin >> previous_word;
    history[previous_word] = true;
    rep(i, n - 1) {
        cin >> word;
        if(word[0] != previous_word[previous_word.size() - 1]) {
            flag = false;
        } else if(history[word]) {
            flag = false;
        }

        previous_word = word;
        history[previous_word] = true;
    }
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}