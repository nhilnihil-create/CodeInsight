#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    int a, b;
    string s;
    cin >> a >> b >> s;
    rep (i, a+b+1) {
        if (i == a) {
            if (s[i] != '-') {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            if (s[i] == '-') {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}