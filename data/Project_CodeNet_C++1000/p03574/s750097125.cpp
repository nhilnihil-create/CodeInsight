
#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector <string> lines(h);
    vector <vector <int>> nums(h+2, vector<int>(w+2, 0));

    for (int i = 0; i < h; i++) {
        cin >> lines.at(i);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (lines.at(i).at(j) == '#') {
                nums.at(i).at(j)++;
                nums.at(i).at(j+1)++;
                nums.at(i).at(j+2)++;
                nums.at(i+1).at(j)++;
                nums.at(i+1).at(j+2)++;
                nums.at(i+2).at(j)++;
                nums.at(i+2).at(j+1)++;
                nums.at(i+2).at(j+2)++;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (lines.at(i).at(j) == '#') {
                cout << '#';
            }
            else {
                cout << nums.at(i+1).at(j+1);
            }
        }
        cout << endl;
    }
    return 0;
}