#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num;
    int x = 0;
    int y = 0;

    cin >> num;
    
    vector<int> vec(num);
    vector<int> vec2(num);
    for (int i = 0; i < num; i++) cin >> vec.at(i);
    for (int i = 0; i < num; i++) cin >> vec2.at(i);

    for (int i = 0; i < num; i++) {
        if (vec.at(i) - vec2.at(i) >= 0) {
            x += vec.at(i);
            y += vec2.at(i);
        }
    }

    cout << x - y<< endl;
    //
}
