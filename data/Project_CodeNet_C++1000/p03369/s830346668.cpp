#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    int val = 700;
    int coun = 0;

    cin >> S;
    for (int i = 0; i < 3; i++){
        if (S[i] == 'o'){
            coun += 1;
        }
    }

    cout << (val + 100*coun) << endl;
}