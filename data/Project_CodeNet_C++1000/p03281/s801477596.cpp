#include <iostream>
#include <cstdlib>
 
using namespace std;
// https://qiita.com/Clpsplug/items/81fe12400d4093a8fb5a
 
int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i < N+1; i++) {
        int counter = 0;
        for (int j = 1; j < i; j++) {
            if (i%j == 0 && j < i/j) {
                counter++;
            }
        }
        if (counter == 4 && i%2 != 0) {
            ans++;
        }
    }

    cout << ans << endl;
}