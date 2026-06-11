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

string s, t;
int main(){
    while (cin >> s >> t) {
        bool ok = false;
        for (int i = 0; i < s.size(); i++) {
            string ss = s.substr(1) + s[0];
            if (ss == t) ok = true;
            s = ss; 
        }
        if (ok) puts("Yes");
        else puts ("No");
    }
}