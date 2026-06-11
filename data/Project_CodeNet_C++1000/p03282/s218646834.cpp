#include <iostream>
using namespace std;
int main() {
    string s;
    long long k;
    cin >> s >> k;
    int result;
    for (int i=0; i<k; i++) {
        if (s[i] != '1' || i == k-1) {
            result = s[i] - '0';
            break;
        }
    }
    cout << result << endl;
}