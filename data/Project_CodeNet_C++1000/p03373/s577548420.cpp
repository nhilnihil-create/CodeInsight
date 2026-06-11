#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, AB;
    int X, Y;
    int sum = 0;
    int minR = 2000000000;
    cin >> A >> B >> AB >> X >> Y; 
    for(int i = 0; i <= 100000; i++) {
        sum = 2*AB*i + max(0, X-i)*A + max(0, Y-i)*B;
        minR = min(sum, minR);
    }
    cout << minR << endl;
    return 0;
}