#include <iostream>
using namespace std;
bool isKaibunsuu(int n) {
    int a[5];
    a[0] = n/10000;
    a[1] = n/1000 - (n/10000)*10;
    a[2] = n/100 - (n/1000)*10;
    a[3] = n/10 - (n/100)*10;
    a[4] = n - (n/10)*10;
    if (a[0]==a[4] && a[1]==a[3]) {
        return true;
    } else {
        return false;
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    int count = 0;
    for (int i=a; i<=b; i++) {
        if (isKaibunsuu(i)) count++;
    }
    cout << count << endl;
}