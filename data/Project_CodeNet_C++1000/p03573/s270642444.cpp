#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C;

    cin >> A >> B >> C;

    if(A == B) {
        cout << C << endl;
    } else if(A == C) {
        cout << B << endl;
    } else {
        cout << A << endl;
    }
}