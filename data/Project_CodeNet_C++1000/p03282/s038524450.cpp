#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    long k;
    cin >> s >> k;

    int n = s.size();

    for (int i=0; i<n; i++) {
        if (i+1 == k) {
            cout << s[i] << endl;
            return 0;
        }
        if (s[i] != '1') {
            cout << s[i] << endl;
            return 0;
        }
    }
}
