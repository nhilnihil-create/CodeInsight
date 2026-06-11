#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    bool a[55556];
    a[1] = false;
    for (int i = 2; i <= 55555; i++) {
        a[i] = true;
    }
    for (int i = 2; i <= 55555; i++) {
        if(a[i]) {
            for (int j = 2 * i; j <= 55555; j += i) {
                a[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    int count = 11;
    while (n) {
        if ((a[count])&&(count%5==1)){
            cout << count << " " ;
            n--;
        }
        count++;
    }
    return 0;
}