#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num[4] = {n / 1000, (n / 100) % 10, (n / 10) % 10, n % 10};
    int sum;
    char op[3];
    bool match = false;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                op[0] = '+', op[1] = '+', op[2] = '+';
                sum = num[0];
                if (i == 1) op[0] = '-';
                if (j == 1) op[1] = '-';
                if (k == 1) op[2] = '-';
                for (int l = 0; l < 3; l++) {
                    if (op[l] == '+') sum += num[l + 1];
                    else
                        sum -= num[l + 1];
                }
                if (sum == 7) {
                    match = true;
                    break;
                }
            }
            if (match) break;
        }
        if (match) break;
    }
    cout << num[0];
    for (int i = 0; i < 3; i++) cout << op[i] << num[i + 1];
    cout << "=7" << endl;
    return 0;
}