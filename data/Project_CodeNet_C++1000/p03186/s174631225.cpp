#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    // take one tasty antidote + one tasty poison = +2 each
    int D = min(B,C);
    int sum = 0;
    sum += 2*D;
    B -= D;
    C -= D;
    //printf("%d %d %d. %d tasty cookies\n", A,B,C,sum);
    // take one untasty antidote + one tasty poison = +1 each
    int E = min(A,C);
    sum += E;
    A -= E;
    C -= E;
    //printf("%d %d %d. %d tasty cookies\n", A,B,C,sum);
    // can you still take one tasty poison?
    if (C>0) {
        C--;
        sum++;
    }
    // take the rest of the untasty antidotes & tasty antidotes, if no more poison
    sum += B;
    A = 0;
    B = 0;
    //printf("%d %d %d. %d tasty cookies\n", A,B,C,sum);
    cout << sum << '\n';
}
