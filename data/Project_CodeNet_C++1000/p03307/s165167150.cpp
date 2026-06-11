#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    if(N % 2) {
        cout << N * 2 << endl;
    } else {
        cout << N << endl;
    }
}   