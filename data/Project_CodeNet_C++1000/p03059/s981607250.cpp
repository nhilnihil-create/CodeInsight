#include <bits/stdc++.h>

using namespace std;
int main()
{
    int A, B, T;
    cin >> A >> B >> T;
    int generated_times = T / A;
    int ans = generated_times * B;
    cout << ans << endl;
}