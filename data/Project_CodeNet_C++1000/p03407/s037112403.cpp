#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    if(C <= A + B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}