#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> food(5);
    for (int i = 0; i < 5; i++) {
        cin >> food.at(i);
    }
    
    vector<int> mod(5);
    for (int i = 0; i < 5; i++) {
        mod.at(i) = food.at(i) % 10;
        if (mod.at(i) == 0) {
            mod.at(i) = 10;
        }
    }
    sort(mod.begin(),mod.end());
    
    for (int i = 0; i < 5; i++) {
        if (mod.at(i) == 10) {
            mod.at(i) = 0;
            continue;
        }
        if (i == 0) {
            continue;
        }
        mod.at(i) = 10;
    }
    
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int buf = food.at(i) / 10;
        sum += buf * 10;
        sum += mod.at(i);
    }
    
    cout << sum << endl;
}
