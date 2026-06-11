#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    int L, L_max, L_sum;
    L_max = 0;
    L_sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> L;
        L_max = max(L, L_max);
        L_sum += L;
    }
    
    if (L_max < L_sum-L_max)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    

}

int main() {
    solve();
    return 0;
}