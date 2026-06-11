# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int prev = N % 10;
    N = N / 10;
    int next = N % 10;
    N = N / 10;
    if (prev == next) {
        next = N % 10;
        if (prev == next)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else {
        prev = next;
        next = N % 10;
        N = N / 10;
        if (prev == next) {
            next = N % 10;
            if (prev == next)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}