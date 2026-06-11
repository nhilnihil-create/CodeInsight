#include <iostream>
using namespace std;
int main() {
    char b;
    cin >> b;
    char base[4] = {'A', 'C', 'T', 'G'};
    for (int i=0; i<4; i++) {
        if (b == base[i]) {
            cout << base[(i+2)%4] << endl;
        }
    }
}