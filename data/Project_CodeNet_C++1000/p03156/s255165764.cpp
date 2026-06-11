#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, A, B;
int P[110];

int main() {
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) cin >> P[i];

    int one = 0, two = 0, three = 0;
    for (int i = 0; i < N; i++) {
        if (P[i] <= A) one++;
        else if (A < P[i] && P[i] <= B) two++;
        else three++;
    }

    cout << min(one, min(two, three)) << endl;

    return 0;
}
