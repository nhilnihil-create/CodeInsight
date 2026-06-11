#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    int N, A, B;
    while (cin >> N >> A >> B) {
        int num[3] = {0};
        for (int i = 0; i < N; ++i) {
            int p; cin >> p;
            if (p <= A) num[0]++;
            else if (p <= B) num[1]++;
            else num[2]++;
        }
        cout << min(num[0], min(num[1], num[2])) << endl;
    }
}
