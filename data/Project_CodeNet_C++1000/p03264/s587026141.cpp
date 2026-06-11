#include <iostream>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL); 
    int K, cont = 0;
    cin >> K;
    for (int i = 2; i <= K; i += 2) {
        for (int j = 1; j <= K; j += 2) {
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}