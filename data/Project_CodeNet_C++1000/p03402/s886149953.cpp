#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
using namespace std;
using Int = long long;
int main()
{
    int a, b;
    cin >> a >> b;
    a--, b--;
    vector<string> vs;
    if (a == 0) {
        string s;
        for (int i = 0; i < 100; i++) s += "#";
        vs.push_back(s);
    }
    while (a) {
        string s;
        for (int i = 0; i < 50; i++) {
            if (a > 0) {
                s += ".#";
                a--;
            } else {
                s += "##";
            }
        }
        vs.push_back(s);
        s = "";
        for (int i = 0; i < 100; i++) s += "#";
        vs.push_back(s);
    }
    if (b == 0) {
        string s;
        for (int i = 0; i < 100; i++) s += ".";
        vs.push_back(s);
    }
    while (b) {
        string s;
        for (int i = 0; i < 100; i++) s += ".";
        vs.push_back(s);
        s = "";
        for (int i = 0; i < 50; i++) {
            if (b > 0) {
                s += "#.";
                b--;
            } else {
                s += "..";
            }
        }
        vs.push_back(s);
    }
    cout << vs.size() << " " << 100 << endl;
    for (auto& line : vs) cout << line << endl;
    return 0;
}
