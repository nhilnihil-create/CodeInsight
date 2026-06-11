#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using str = string;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    str S, T;
    cin >> S >> T;
    int N = S.size();
    for(int i = 0; i < N; i++) {
        if(S == T) {
            cout << "Yes" << endl;
            return 0;
        }
        else {
            str U = S;
            for(int j = 0; j < N; j++){
                S[(j + 1) % N] = U[j];
            }
        }
    }
	cout << "No" << endl;
    return 0;
}