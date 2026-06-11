#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

using ll = unsigned long long;

int main ()
{
    int n;
    string s;
    cin >> n >> s;

    // 左にある黒
    vector<int> black(s.size() + 2, 0);
    // 右にある白
    vector<int> white(s.size() + 2, 0);

    for (int i = 1; i <= s.size(); i++) {
        if (s[i - 1] == '#') {
            black[i] = black[i - 1] + 1;
        } else {
            black[i] = black[i - 1];
        }
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != '#') {
            white[i] = white[i + 1] + 1;
        } else {
            white[i] = white[i + 1];
        }
    }

    int result = 9999999;
    for (int i = 0; i <= s.size(); i++) {
        int tmp = black[i] + white[i];
        result = min(tmp, result);
    }

    cout << result << endl;
}
