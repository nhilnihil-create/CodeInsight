#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    vector<string> s;
    for (int i = 0; i < h; i++) {
        /* code */
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }

    for (int i = 0; i < h; i++) {
        /* code */
        // cout << s[i] << endl;
        for (int j = 0; j < w; j++) {
            /* code */
            if (s[i][j] == '#') {
                bool flag = false;
                for (int k = 0; k < 4; k++) {
                    /* code */
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < h && y >= 0 && y < w && s[x][y] == '#') {
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
}