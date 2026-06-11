#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> v;
    for (int i = 0; i < H; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }
    vector<string> answer(H);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            int tmp = 0;
            if (v.at(i).at(j) == '.'){
                if (i > 0 && v.at(i - 1).at(j) == '#') tmp++;
                if (i < H - 1 && v.at(i + 1).at(j) == '#') tmp++;
                if (j > 0 && v.at(i).at(j - 1) == '#') tmp++;
                if (j < W - 1 && v.at(i).at(j + 1) == '#') tmp++;
                if (i > 0 && j > 0 && v.at(i - 1).at(j - 1) == '#') tmp++;
                if (i > 0 && j < W - 1 && v.at(i - 1).at(j + 1) == '#') tmp++;
                if (i < H - 1 && j > 0 && v.at(i + 1).at(j - 1) == '#') tmp++;
                if (i < H - 1 && j < W - 1 && v.at(i + 1).at(j + 1) == '#') tmp++;
                answer.at(i).push_back(char(tmp + '0'));
            }
            else{
                answer.at(i).push_back('#');
            }
        }
    }
    for (int i = 0; i < H; i++){
        cout << answer.at(i) << endl;
}
}