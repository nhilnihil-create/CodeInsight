#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> a(100005);
int num = 0;

int f(int x) {
    if (a.at(x) == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (a.at(x) == 2) {
        num++;
        cout << num << endl;
        return 0;
    }
    int y = a.at(x);
    a.at(x) = 0;
    num++;
    f(y);
    return 0;
}

int main() {
    int N;
  	cin >> N;
    vector<vector<int>> vec(2, vector<int>(N));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> vec.at(i).at(j);
        }
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        int x = 0;
        for (int j = 0; j <= i; j++) {
            x += vec.at(0).at(j);
        }
        for (int j = i; j < N; j++) {
            x += vec.at(1).at(j);
        }
      	//cout << x << endl;
        if (x > max) max = x;
    }
    cout << max << endl;
}