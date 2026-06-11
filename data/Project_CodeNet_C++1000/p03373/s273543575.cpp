#include <iostream>

using namespace std;

int main() {
    int a, b, c, x, y;
    int i, j, k;
    int ans[3];
    cin  >> a >> b >> c >> x >> y;
    int price = INT_MAX;

    if (x > y) {
        for (i = 0; i <= x; i++) {
            j = max(y-x+i, 0);
            k = 2*(x - i);
            int tmp = a*i + b*j + c*k;
            if (tmp < price) {
                price = tmp;
                ans[0] = i;
                ans[1] = j; 
                ans[2] = k;
            }
        }
    }
    else {
        for (j = 0; j <= y; j++) {
            k = 2*(y - j);
            i = max(x-y+j, 0);
            int tmp = a*i + b*j + c*k;
            if (tmp < price) {
                price = tmp;
                ans[0] = i;
                ans[1] = j; 
                ans[2] = k;
            }
        }
    }
    cout << a*ans[0] + b*ans[1] + c*ans[2] << endl;
    return 0;
}