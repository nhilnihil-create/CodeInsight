#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> m(h, vector<int>(w, 1));
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < w; j++){
            m.at(i).at(j) = 0;
        }
    }
    for (int i = 0; i < b; i++){
        for (int j = 0; j < h; j++){
            m.at(j).at(i) = 0;
        }
    }
    
    int count = 0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (m.at(i).at(j) == 1){
                count++;
            }
        }
    }
    cout << count << endl;
    
}