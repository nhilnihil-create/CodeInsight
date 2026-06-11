#include <iostream>
using namespace std;
int lcm(int a, int b) {
    if (a%b == 0) {
        return b;
    } else {
        return lcm(b, a%b);
    }
}
int main() {
    int n;
    cin >> n;
    int result;
    cin >>result;
    for (int i=0; i<n-1; i++) {
        int a;
        cin >> a;
        result = lcm(result, a);
    }
    cout << result << endl;
}