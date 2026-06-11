#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> A(3);

    for(int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    int K;
    cin >> K;

    int a = *max_element(A.begin(), A.end());

    int ans = 0;

    for(int i = 0; i < 3; i++) {
        if(A[i] == a) {
            ans += A[i] * pow(2, K);
            a = 0;
        }
        else ans += A[i];
    }

    cout << ans << endl;
}