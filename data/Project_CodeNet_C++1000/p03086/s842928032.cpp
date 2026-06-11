//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
using namespace std;
// using ll = long long int;

void inv(vector<int>& v) {
    int length = v.size();
    for (int i = 0; i < length; i++) {
        cin >> v[i];
    }
}
void inv(vector<int>& v, int length) {
    for (int i = 0; i < length; i++) {
        cin >> v[i];
    }
}

int main() {
    string s;
    cin >> s;

    int smax = 0;
    int slength = (int)s.size();
    rep(i, 0, slength) {
        int index = i;
        int cnt = 0;
        while (index < slength) {
            if (s[index] == 'A' || s[index] == 'C' || s[index] == 'G' ||
                s[index] == 'T') {
                index++;
                smax = max(smax, ++cnt);
            } else {
                break;
            }
        }
    }
    cout << smax << endl;
    return 0;
}
