#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> s(h+2, vector<char>(w+2, '.'));
    for (int i=1; i<h+1; i++) {
        for (int j=1; j<w+1; j++) {
            cin >> s.at(i).at(j);
        }
    }

    for (int i=1; i<h+1; i++) {
        for (int j=1; j<w+1; j++) {
            int bcnt=0;
            if (s.at(i).at(j) != '#') {
                for (int x=-1; x<=1; x++) {
                    for (int y=-1; y<=1; y++) {
                        if (s.at(i+x).at(j+y)=='#') bcnt++;
                    }
                }
                s.at(i).at(j)='0'+bcnt;
            }
        }
    }

    for (int i=1; i<h+1; i++) {
        for (int j=1; j<w+1; j++) {
            cout << s.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}