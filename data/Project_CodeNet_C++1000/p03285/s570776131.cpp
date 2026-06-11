#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;

    cin >> num;

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if(i*4 + j*7 == num){
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
    //
}
