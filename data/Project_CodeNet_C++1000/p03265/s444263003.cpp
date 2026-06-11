#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int vector_x = x2 - x1;
    int vector_y = y2 - y1;
    
    int x3 = x2 - vector_y;
    int y3 = y2 + vector_x;
    int x4 = x3 - vector_x;
    int y4 = y3 - vector_y;

    cout << x3 << " " << y3 << " " << x4 << " " << y4;
    return 0;

}