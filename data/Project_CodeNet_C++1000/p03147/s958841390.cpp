#include <bits/stdc++.h>
using namespace std;



















int water (vector<int> h) {
    int result = 0;

    int N = h.size();
    vector<int> allzero(N, 0);

    while (h != allzero) {
        int count = 0;
        while (h[count] == 0) count++;

        while (count < N) {
            int count1 = count;
            int minimum = 100;

            while (count < N && h[count] != 0) {
                minimum = min (minimum, h[count]);
                count++;
            }

            result += minimum;
            for (int i = count1; i <= count - 1; i++) {
                h[i] -= minimum;
            }

            while (count < N && h[count] == 0) count++;
        } 
    }
    return result;
}








int main () {
    int N;
    cin >> N;
    vector<int> h(N);

    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    cout << water(h) << endl;
}