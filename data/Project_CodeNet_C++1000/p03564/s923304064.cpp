#include <iostream>
using namespace std;

int main() {
    int N = 0, K = 0;
    cin >> N >> K;
    int num = 1;

    for(int i = 0; i < N; i++) {
        if(num*2 < num+K) {
            num *= 2;
        } else {
            num += K;
        }
    }
    cout << num << endl;
}