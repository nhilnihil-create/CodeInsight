#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c;
    int S;
    cin >> a >> b >> c;

    double s = (a + b + c) / 2;
    double S_1 = sqrt(s * (s - (double) a) * (s - (double) b) * (s - (double) c));
    int S_0 = int (S_1);
    cout << S_1 << endl;
    return 0;
}