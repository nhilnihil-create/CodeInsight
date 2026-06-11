#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int A[110];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    int cnt = 0;
    int tmp = A[0];
    for (int i = 1; i < N; i++) {
        if (tmp == A[i]) {
            cnt++;
        }
        else {
            ans += (cnt+1)/2;
            cnt = 0;
        }
        tmp = A[i];
    }
    ans += (cnt+1)/2;


    cout << ans << endl;

    return 0;
}
