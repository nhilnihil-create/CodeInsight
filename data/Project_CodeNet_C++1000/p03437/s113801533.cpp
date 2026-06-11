#include <iostream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    if(x%y == 0){
        cout << "-1";
    } else {
        cout << x;
    }
}