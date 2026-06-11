#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    int cnt = 0;
    string s;

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            cnt++;
        }
    }

    if (cnt > n/2) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
