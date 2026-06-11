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

    int max = *max_element(A.begin(), A.end());
    int min = *min_element(A.begin(), A.end());

    cout << max - min << endl;
}   