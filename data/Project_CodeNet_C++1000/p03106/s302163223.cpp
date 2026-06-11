#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, a, b, k, count = 0;
    cin >> a >> b >> k;
    n = (a > b) ? b : a;
    for (int i = n; n > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            count++;
            if (count == k) {
                cout << i << endl;
                break;
            }
        }
    }

}