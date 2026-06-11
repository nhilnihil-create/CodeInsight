#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        bool flag = true;
        string s = to_string(i);
        for (int j = 0; j < 2; j++) {
           if (s[j] != s[4-j]) {
               flag = false;
           } 
        }
        if (flag) ans++;
    }
    cout << ans << endl;
}