#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int b = 0;
    long long sum = 0;
    for (int i=0; i<(int)(s.length()); i++) {
        if (s[i] == 'B') {
            b++;
        } else {
            sum += b;
        }
    }
    cout << sum << endl;
}