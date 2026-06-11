#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s;
    cin >> s;
    int x = stoi(s.substr(0, 2)); // "00"→0に変換される
    int y = stoi(s.substr(2, 2));
    if ((0 < x && x <= 12) && (0 < y && y <= 12)){
        cout << "AMBIGUOUS" << endl;
    }
    else if((0 < x && x <= 12) && (y > 12 || y == 0)){
        cout << "MMYY" << endl;
    }
    else if ((x > 12 || x == 0) && (0 < y && y <= 12)){
        cout << "YYMM" << endl;
    }
    else cout << "NA" << endl;
}