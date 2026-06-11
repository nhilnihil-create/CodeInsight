#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
	string S;
    cin >> N >> K;
  	cin >> S;
    for (int i = 0; i < N; i++) {
        if (i == K - 1) S[i] = S[i] + 0x20;
    }
    cout << S << endl;
}