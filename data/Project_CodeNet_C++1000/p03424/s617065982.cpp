#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string s;
    bool isThree = true;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> s;
        if(s == "Y") {
            isThree = false;
            break;
        }
    }

    if(isThree) {
        cout << "Three" << endl;
    } else {
        cout << "Four" << endl;
    }
}
