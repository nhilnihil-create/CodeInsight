#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    long sum;
    long sum_soms = 0;
    string s;
    for (int i = 1; i < n + 1; i++) {
        s = to_string(i);
        sum = 0;
        for (int j = 0; j < s.size(); j++) {
            sum += s[j] - '0';
        }
        if (sum >= a && sum <= b) sum_soms += i;
    }
    cout << sum_soms << endl;
}