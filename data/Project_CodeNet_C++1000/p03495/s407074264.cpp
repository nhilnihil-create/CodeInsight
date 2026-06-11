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
        int a;
        cin >> a;
        a--;
        A[a]++;
    }

    int c = 0;

    vector<int> x;

    for(int i = 0; i < N; i++) {
        if(A[i]) {
            c++;
            x.push_back(A[i]);
        }
    }

    if(c <= K) {
        cout << 0 << endl;
        return 0;
    }

    sort(x.begin(), x.end());

    int ans = 0;

    for(int i = 0; i < c - K; i++) {
        ans += x[i];
    }

    cout << ans << endl;
}