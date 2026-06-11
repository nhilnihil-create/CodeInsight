#include <iostream>
using namespace std;

int A[200];
int main() {
    int N;
    cin >> N;

    int count = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    while(1) {
        bool odd = false;
        for(int i = 0; i < N; i++) {
            if(A[i] % 2 == 1) {
                odd = true;
            }
        }
        if(odd) break;
        count++;
        for(int i = 0; i < N; i++) {
            A[i] /= 2;
        }
    }
    cout << count << endl;
}