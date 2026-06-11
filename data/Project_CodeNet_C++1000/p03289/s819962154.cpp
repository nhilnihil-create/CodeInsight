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
    string s;
    cin >> s;
    bool ans = true;
    int cou = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            if (s[i] != 'A') ans = false; 
        }
        else if (i >= 2 && i <= s.size()-2 && s[i] == 'C') {
            cou++;
            if (cou > 1) ans = false;
        }
        else if (!islower(s[i])) ans = false;
    }
    if (cou == 0) ans = false;

    if(ans) cout << "AC" << endl;
    else cout << "WA" << endl;

    return 0;
}