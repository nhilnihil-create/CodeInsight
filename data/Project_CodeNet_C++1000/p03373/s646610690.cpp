#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, x, y;
    int sumA;
    int sumB;
    int sumC;
    cin >> a >> b >> c >> x >> y;
    sumA = a * x + b * y;
    if (x > y){
        sumB = x * 2 * c;
    } else {
        sumB = y * 2 * c;
    }
    if (x > y){
        sumC = y * 2 * c;
        sumC += (x - y) * a;
    } else {
        sumC = x * 2 * c;
        sumC += (y - x) * b;
    }
    int ret = min({sumA, sumB, sumC});
    cout << ret << endl;
    return 0;
}