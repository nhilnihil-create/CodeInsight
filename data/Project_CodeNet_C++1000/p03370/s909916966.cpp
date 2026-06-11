#include <iostream>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    int m[110000];
    int sum  = 0;
    int min = 1100;
    for(int i = 0; i < N; i++) {
        cin >> m[i];
        sum += m[i];
        if(min > m[i]) {
            min = m[i];
        }
    }
    cout << N + (X-sum)/min << endl;
}