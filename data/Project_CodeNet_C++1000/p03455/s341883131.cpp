#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if(a * b % 2) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }
}