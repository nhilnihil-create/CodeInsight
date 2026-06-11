#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    if(A % 2 && B % 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}