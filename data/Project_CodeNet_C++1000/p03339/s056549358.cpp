#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int e_num = 0;
    for (int i = 0; i < N; i++) {
        if (S.at(i) == 'E')  e_num++;
    }

    int min;
    if (S.at(0) == 'E') min = e_num - 1;
    else min = e_num;

    int x = min;
    for (int i = 1; i < N; i++) {
        if (S.at(i) == 'E' && S.at(i - 1) == 'E') {
            x--;
            if (min > x) min = x;
        }
        if (S.at(i) == 'W' && S.at(i - 1) == 'W') {
            x++;
        }
    }
    cout << min << endl;
}