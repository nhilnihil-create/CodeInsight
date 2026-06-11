#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
    int n;
    string s;
    cin >> n >> s;
    int cou = count(s.begin(), s.end(), '.');
    int min = cou;
    for (auto c : s) {
        if (c == '#')
            cou++;
        else
            cou--;
        if (cou < min)
            min = cou;
    }
    cout << min << endl;
}