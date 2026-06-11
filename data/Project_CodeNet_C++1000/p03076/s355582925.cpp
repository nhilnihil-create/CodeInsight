#include <iostream>
using namespace std;
int main() {
    int maxplus = 0;
    int result = 0;
    for (int i=0; i<5; i++) {
        int a;
        cin >> a;
        int aplus = ((a%10 == 0)? 0 : 10 - a%10);
        maxplus = max(aplus, maxplus);
        result += a + aplus;
    }
    cout << result - maxplus << endl;
}