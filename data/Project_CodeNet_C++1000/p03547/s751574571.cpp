#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    char X, Y;
    cin >> X >> Y;

    if(X > Y) {
        cout << ">" << endl;
    } else if(Y > X) {
        cout << "<" << endl;
    } else {
        cout << "=" << endl;
    }
}