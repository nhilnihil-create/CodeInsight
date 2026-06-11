#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

signed main() 
{
    int x1,y1,x2,y2,x3,y3,x4,y4; 
    cin >> x1 >> y1 >> x2 >> y2; 

    x3 = x2 +(y1-y2);
    y3 = y2 -(x1-x2);

    x4 = x3 + x1-x2;
    y4 = y3 + y1-y2;

    cout << x3 << " " << y3 <<" " << x4 << " " << y4; 
    return 0;
}
