#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int main() {
    vector<vector<char>> c(3, vector<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c.at(i).at(j);
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << c.at(i).at(i);
    }
    cout << endl;
}