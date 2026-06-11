#include <iostream>
using namespace std;

int main() {
    int N, count, result=0;
    cin >> N;
    for (int i = 1; i < N + 1; i++)
    {
        count = 0;
        if (i % 2 == 0) continue;
        else {
            for (int j=1; j < i + 1; j++) {
                if (i % j == 0) count++; 
            }
            if (count == 8) result++;
        }
    }
    cout << result << endl;
    return 0;
}