#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    if(N % K == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}