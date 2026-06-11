#define P(x) cout << #x " = " << x << endl
#define PP(x, y) cout << "(" #x ", " #y ") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "(" #x ", " #y ", " #z ") = (" << x << ", " << y << ", " << z << ")" << endl

#include<iostream>
#include<vector>
#include<cassert>
#include<cmath>
#include<string>

using namespace std;

int n, q;
string s;
string t;
string d;

int main()
{
    string s;
    cin >> n >> q;
    cin >> s;
    char tmp;
    for (int i = 0; i < q; ++i) {
        cin >> tmp;
        t += tmp;
        cin >> tmp;
        d += tmp;
    }
    int left = 0;
    int right = n;

    for (int i = 0; i < q; ++i) {
        char ti = t[q - i - 1];
        char di = d[q - i - 1];
        if (di == 'R') {
            if (s[right - 1] == ti) right--;
            if (left != 0 && s[left - 1] == ti) left--;
        } else {
            if (right != n && s[right] == ti) right++;
            if (s[left] == ti) left++;
        }
        if (right == left) break;
    }
    cout << right - left << endl;
}