#include<iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    // 全体の差をとっていく
    array<int, 3> x;
    for(int i =0; i < 3; i++){
         cin >> x[i];
    }
    sort(x.begin(), x.end());

    //cout << x << endl;
    // for (auto a : x) {
    //     std::cout << a << " ";
    // }
    // for(int i = 0; i < 5; i++){
    //     cout << x[i] << endl;
    // }   
    int abs = 0;
    for(int i = 0; i < 2; i++){
        abs += (x[i+1] - x[i]);
    }
    cout << abs << endl;
}