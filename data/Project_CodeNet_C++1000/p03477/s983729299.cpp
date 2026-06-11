#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if(A + B > C + D) {
        cout << "Left" << endl;
    } else if(A + B < C + D) {
        cout << "Right" << endl;
    } else {
        cout << "Balanced" << endl;
    }
}