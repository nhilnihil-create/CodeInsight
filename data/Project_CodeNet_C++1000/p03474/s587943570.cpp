#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (i == A && S.at(i) != '-') {
            cout << "No" << endl;
            return 0;
        }
        if (i != A && S.at(i) == '-') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}