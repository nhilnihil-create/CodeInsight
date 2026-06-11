#include <bits/stdc++.h>
using namespace std;

void print_num_bombs(vector <vector<int>> s) {
    int h = s.size();
    int w = s.at(0).size();
    for (int i = 1; i < h-1; i++) {
        for (int j = 1; j < w-1; j++) {
            if (s.at(i).at(j) == 0) {
                int nb = s.at(i-1).at(j-1) +
                    s.at(i-1).at(j) +
                    s.at(i-1).at(j+1) +
                    s.at(i).at(j-1) +
                    s.at(i).at(j+1) +
                    s.at(i+1).at(j-1) +
                    s.at(i+1).at(j) +
                    s.at(i+1).at(j+1);
                cout << nb;
            } else cout << "#";
        }
        cout << endl;
    }
}

int main() {
    int h, w;
    char tmp;
    cin >> h >> w;
    vector <vector<int>> s(h+2, vector<int>(w+2));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> tmp;
            if (tmp == '#') s[i+1][j+1] = 1;
            else s[i+1][j+1] = 0;
        }
    }
    print_num_bombs(s);

    return 0;
}
