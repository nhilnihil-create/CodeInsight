#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= 55555 && n > 0; i += 5) {
        int flag = 1;
        int num = i;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cout << i << " ";
            n--;
        }
    }
    cout << endl;
}
