#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(((N+1)/2)*2,0);
    for(int i = 0; i < N; i++) {
    cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    int ans = 0;
    for (size_t i = 0; i < (N+1)/2; i++)
    {
        ans += A.at(i*2) - A.at(2*i+1);
    }

    cout << ans << endl;
    return 0;
}