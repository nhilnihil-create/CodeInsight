#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R')count++;
        else count--;
    }
    cout << (count > 0 ? "Yes" : "No") << endl;
    return 0;
}