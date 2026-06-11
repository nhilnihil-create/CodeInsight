#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j]) {
                cout << "No" << endl;
                return 0;
            }
        }
        if (s[i-1][s[i-1].size()-1] != s[i][0]) {
            cout << "No" << endl;
            return 0;
        } 
    }

    cout << "Yes" << endl;

    return 0;
}