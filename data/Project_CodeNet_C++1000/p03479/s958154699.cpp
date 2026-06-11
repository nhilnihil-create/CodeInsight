#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;
    int ans = 1;
    while (x <= y) {
        x *= 2;
        ans++;
    }
    cout << --ans << endl;
}