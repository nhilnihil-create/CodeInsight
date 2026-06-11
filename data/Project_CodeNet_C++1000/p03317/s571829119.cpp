#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
    

    int N, K;
    cin >> N >> K;

    vector<int> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    N--;
    K--;

    int ans = N / K;

    if(N % K) ans++;

    cout << ans << endl;
}