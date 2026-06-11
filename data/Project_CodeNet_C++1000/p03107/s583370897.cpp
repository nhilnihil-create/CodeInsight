#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    //前にブロックがないときはprev='2'とする
    char prev = '2', now;
    int cnt = 0;
    for (int i=0; i<s.size(); i++) {
        now = s[i];
        if (now == prev || prev == '2') {
            cnt++;
            prev = now;
        } else {
            cnt--;
            if (cnt == 0) {
                prev = '2';
            }
        }
    }
    cout << s.size() - cnt << endl;
}