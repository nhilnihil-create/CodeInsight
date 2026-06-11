#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int N, D, X;
    cin >> N >> D >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= D; i++) {
        for (int j = 0; j < N; j++) {
            int cho = A[j] * i + 1;
            if (cho <= D) {
                ans++;
            }
        }
    }
    cout << ans + N + X << endl;
}