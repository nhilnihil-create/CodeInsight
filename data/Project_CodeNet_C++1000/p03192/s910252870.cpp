#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string N;

int main() {
    cin >> N;

    int two = 0;
    for (int i = 0; i < 4; i++) {
        if (N[i] == '2') two++;
    }

    cout << two << endl;


    return 0;
}
