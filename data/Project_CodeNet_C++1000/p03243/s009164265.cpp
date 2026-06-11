#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = N; i < 1000; i++) {
        if (i % 111 == 0) {
            cout << i << endl;
            break;
        }
    }
}
