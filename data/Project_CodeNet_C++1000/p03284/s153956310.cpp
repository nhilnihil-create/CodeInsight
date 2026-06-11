#include<iostream>
using namespace std;


int N, K;

void read() {
    cin >> N >> K;
}


void work() {
    cout << (N % K == 0 ? 0 : 1) << endl;
}


int main() {
    read();
    work();
    return 0;
}
