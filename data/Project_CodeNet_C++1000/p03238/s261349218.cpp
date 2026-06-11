#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int N, A, B;


void input() {
    cin >> N;
}


int main() {
    input();
    if (N == 1) cout << "Hello World" << endl;
    else {
        cin >> A >> B;
        cout << A + B << endl;
    }
}
