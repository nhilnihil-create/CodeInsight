#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin>>N;
    int i = 1;
    while (i * i <= N) {
        i++;
    }
    cout << (i - 1) * (i - 1) << endl;
    return 0;
}