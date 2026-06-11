#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N, A, B;
    int p, ans;
    int one = 0;
    int two = 0;
    int three = 0;

    cin >> N;
    cin >> A >> B;

    for (int i = 0; i < N; i++) {
        cin >> p;
        if (p <= A) {
            one++;
        } else if (p >= A+1 && p <= B) {
            two++;
        } else {
            three++;
        }
    }

    ans = min({one, two, three});

    cout << ans << endl;
}
