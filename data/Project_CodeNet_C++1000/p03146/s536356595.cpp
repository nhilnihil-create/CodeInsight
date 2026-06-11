#include <iostream>
using namespace std;
int function(int n) {
    return ((n%2==0)? n/2 : 3*n+1);
}
int main() {
    int s;
    cin >> s;
    int result;
    if (s == 1 || s == 2 || s == 4) {
        result = 4;
    } else {
        int cnt = 1;
        while (s != 4) {
            s = function(s);
            cnt++;
        }
        result = cnt + 3;
    }
    cout << result << endl;
}