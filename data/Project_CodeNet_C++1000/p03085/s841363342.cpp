#include <bits/stdc++.h>
using namespace std;

char e[] = { 'A', 'C', 'T', 'G'};

int main() {

    char b;
    cin >> b;
    int retp;
    for(int i = 0; i < 4; i++) {
        if(e[i] == b) {
            retp = (i + 2) % 4;
        }
    }

    cout << e[retp] << endl;
}
