#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    int a, b;

    if(K % 2) {
        a = K / 2 + 1;
    } else {
        a = K / 2;
    }

    b = K / 2;

    cout << a * b << endl;
}