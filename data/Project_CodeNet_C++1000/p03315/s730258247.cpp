#include <iostream>
using namespace std;
int main() {
    string S; cin >> S;
    int cnt = 0;
    for (char c : S) {
        if (c == '+') cnt++;
        else cnt--;
    }
    printf("%d\n", cnt);
}