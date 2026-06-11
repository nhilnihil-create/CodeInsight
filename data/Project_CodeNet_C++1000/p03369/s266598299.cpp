#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int c = 0;
    for (int i = 0; i < 3; i++)
    {
        if(S[i] == 'o') c++;
    }
    int sum = 700 + 100 * c;
    cout << sum << endl;
}