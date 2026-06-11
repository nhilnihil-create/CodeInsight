#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    bool color_types[] = {0,0,0,0};
    for (int i = 0; i < N; ++i){
        string color;
        cin >> color;
        if (color == "P"){
            color_types[0] = true;
        } else if (color == "W"){
            color_types[1] = true;
        } else if (color == "G"){
            color_types[2] = true;
        } else if (color == "Y"){
            color_types[3] = true;
        }
    }
    int sum_color_types = 0;
    for (int c : color_types){
        sum_color_types += c;
    }
    if (sum_color_types == 3){
        cout << "Three" << endl;
    } else if (sum_color_types == 4){
        cout << "Four" << endl;
    }
}
