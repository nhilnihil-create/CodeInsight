#include <bits/stdc++.h>
using namespace std;

bool draw(vector<string> &map, int i, int j){
    if (i-1 >= 0){
        if (map.at(i-1).at(j) == '#'){
            return false;
        }
    }

    if (i+1 <= map.size()-1){
        if (map.at(i+1).at(j) == '#'){
            return false;
        }
    }

    if (j-1 >= 0){
        if (map.at(i).at(j-1) == '#'){
            return false;
        }
    }

    if (j+1 <= map.at(0).size()-1){
        if (map.at(i).at(j+1) == '#'){
            return false;
        }
    }

    return true;
}

int main(){
    int h, w;
    cin >> h >> w;

    vector<string> map(h);
    for (int i = 0; i<h; i++){
        cin >> map.at(i);
    }

    for (int i = 0; i<h; i++){
        for (int j = 0; j<w; j++){
            if (map.at(i).at(j) == '#'){
                if (draw(map, i, j)){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
}