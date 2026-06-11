#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    long long s;
    cin >> s;
    int i = 1;
    vector<bool> A(1000010,0);
    while (1) {
        if(A.at(s)) {
            cout << i << endl;
            break;
        } else {

            A.at(s) = 1;
            if(s%2) {
                s = 3*s + 1;
            } else {
                s /= 2;
            }
            i++;
        }
    }
    

    return 0;
}