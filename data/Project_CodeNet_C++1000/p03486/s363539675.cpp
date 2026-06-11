#include<bits/stdc++.h>
using namespace std;

int main(void) {
    string a;
    string b;
    cin >> a >> b;

    int a_len = a.length();
    int b_len = b.length();
    int m_len  = (a_len < b_len ? a_len : b_len);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<char>());

 //   cout << a << endl;
 //   cout << b << endl;

    bool h = false;

    for (int i = 0; i < m_len; i++) {
        if (a[i] < b[i]) {
            h = true;
            break;
        } else if (a[i] > b[i]) {
            h = false;
            break;
        } else if (i == (m_len - 1)) {
            if (a_len < b_len) {
                h = true;
                break;
            } else {
                h = false;
                break;
            }
        } else {
            /* nothing to do. */
        }
    }

    if (h == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
