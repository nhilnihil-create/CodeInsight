#include <bits/stdc++.h>
#include <algorithm>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string N;
    int count = 0;
    cin >> N;
    for (int i = 0; i < N.size(); ++i) {
        if (N[i] == '2') ++count;
    }
    cout << count << endl;
    return 0;
}
