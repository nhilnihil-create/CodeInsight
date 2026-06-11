#include <iostream>
#include <cstdlib>
 
using namespace std;
// https://qiita.com/Clpsplug/items/81fe12400d4093a8fb5a
 
int main() {
    string S;
    cin >> S;

    int counter = 0;
    int max_counter = 0;
    int N = S.length();
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
            counter++;
            if (max_counter < counter) {
                max_counter = counter;
            }
        } else {
            if (max_counter < counter) {
                max_counter = counter;
            }
            counter = 0;
        }
    }

    cout << max_counter << endl;
}