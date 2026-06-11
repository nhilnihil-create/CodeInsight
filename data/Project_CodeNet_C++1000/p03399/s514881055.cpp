#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << min(A, B) + min(C, D) << endl;
}