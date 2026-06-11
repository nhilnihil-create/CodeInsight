#include<iostream>
using namespace std;

int main() {
    int s; cin >> s;
    int arr[10000] = {0};
    int i = 1;
    while(1) {
        if (arr[s] == 1) {
            cout << i << endl;
            break;
        }
        arr[s] = 1;
        if (s % 2 == 0) {
            s /= 2;
        } else {
            s = 3 * s + 1;
        }
        i++;
    }
}
